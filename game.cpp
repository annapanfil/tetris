#include "game.hpp"

Game::Game(){
  const int PIXEL = 20;
  this -> window = new sf::RenderWindow (sf::VideoMode(400,600), "Tetris", sf::Style::Close | sf::Style::Titlebar); //TODO: from board dimensions //sf::Style::Close || sf::Style::Titlebar
  this -> board = new Board (400, 600, PIXEL);
  this -> piece = new Piece(this->board);
  this -> stack = new Stack(this->board);
}

void Game::display_text(sf::Font* font, std::string msg){
  sf::Text text;
  text.setFont(*font);
  text.setString(msg);
  window -> clear();
  window -> draw(text);
  window -> display();
}

void Game::introduce(){
  sf::Font font;
  if (!font.loadFromFile("graphics/font.ttf"))
    std::cout<<"Font error";
  for (int i=3; i>=0; i--){
    display_text(&font, "Hello!\nGame starts in\n" + std::to_string(i));
    sf::sleep(sf::seconds(1));
  }
}

void Game::finish(){

}

void Game::update(){
  piece->move_down();
  if (stack->check_collision(piece)){
      delete this->piece;
      this->piece = new Piece(this->board);
  }
  if (stack->get_border() <=0 )
    finish();
}

void Game::event_handling(){
  sf::Event event;
  while (window -> pollEvent(event)){
    //process events
    switch(event.type){
      case sf::Event::Closed:
        window -> close(); break;
      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Left){
          piece->move_horizontally(-1, stack);
        }
        else if (event.key.code == sf::Keyboard::Right){
          piece->move_horizontally(1, stack);
        }
        else if (event.key.code == sf::Keyboard::X || event.key.code == sf::Keyboard::Up)
          piece->rotate_clockwise();
        else if (event.key.code == sf::Keyboard::Z)
          piece->rotate_counterclockwise();
        else if (event.key.code == sf::Keyboard::Down)
          update();
        else if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::Escape)
          paused = true;
          break;
        default: break;
    }
  }
}

void Game::start(){
  sf::Clock game_clock;
  sf::Clock key_clock;
  int fall_time = 1.5;
  // introduce();

  window -> clear(); //można podać kolor
  //game loop
  while (window->isOpen()){
    if (!paused){
    while (game_clock.getElapsedTime() < sf::seconds(fall_time)){
      event_handling();
      window -> clear();
      window -> draw(*piece);
      window -> draw(*stack);
      window -> display();
    }
    update();
    game_clock.restart();
    }
    else{
      // std::cout<<"paused"<<std::endl;
      sf::Event event;
      while (window -> pollEvent(event)){
        //process events
        std::cout<<"paused"<<std::endl; //żeby się 2h nie zastanawiać
        switch(event.type){
          case sf::Event::Closed:
            window -> close(); break;
          case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::Escape){
              paused = false;
            }
          default: break;
        }
      }
    }
  }
}
