#include "game.hpp"

Game::Game(){
  const int PIXEL = 20;
  this -> window = new sf::RenderWindow (sf::VideoMode(400,600), "Tetris", sf::Style::Close | sf::Style::Titlebar); //TODO: from board dimensions //sf::Style::Close || sf::Style::Titlebar
  this -> board = new Board (400, 600, PIXEL);
  this -> piece = new Piece(this->board);
  this -> stack = new Stack(this->board);
}

void Game::event_handling(){
  sf::Event event;
  while (window -> pollEvent(event)){
    //process events
    switch(event.type){
      case sf::Event::Closed:
        window -> close(); break;
      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Left)
          piece->move_horizontally(-1);
        else if (event.key.code == sf::Keyboard::Right)
          piece->move_horizontally(1);
        else if (event.key.code == sf::Keyboard::X || event.key.code == sf::Keyboard::Up)
          piece->rotate_clockwise();
        else if (event.key.code == sf::Keyboard::Z)
          piece->rotate_counterclockwise();
        else if (event.key.code == sf::Keyboard::Down)
          piece->move_down();
        else if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::Escape)
          paused = true;
          break;
        default: break;
    }
  }
  // }
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  // {
  //   piece->move_horizontally(-1);
  //   sf::sleep(sf::milliseconds(1000/10));
  // }
  // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  // {
  //   piece->move_horizontally(1);
  //   sf::sleep(sf::milliseconds(1000/10));
  // }

    // case sf::Event::Resized:
    //   std::cout<<event.size.width;
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

void Game::start(){
  sf::Clock game_clock;
  sf::Clock key_clock;
  int fall_time = 1.5;

  window -> clear(); //można podać kolor
  //game loop
  while (window->isOpen()){
    if (!paused){
    while (game_clock.getElapsedTime() < sf::seconds(fall_time)){
      event_handling();
      window -> clear(); //można podać kolor
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
