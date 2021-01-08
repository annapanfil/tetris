#include "game.hpp"
#include <cmath>


Game::Game(){
  const int PIXEL = 20;
  this -> window = new sf::RenderWindow (sf::VideoMode(400,600), "Tetris", sf::Style::Close | sf::Style::Titlebar); //TODO: from board dimensions //sf::Style::Close || sf::Style::Titlebar
  this -> board = new Board (400, 600, PIXEL);
  this -> piece = new Piece(floor(((400-PIXEL)/2)/20)*20,0, this->board);
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
          this->paused = true;
          break;
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

void Game::update(){
  piece->move_down();
}


void Game::start(){
  sf::Clock game_clock;
  sf::Clock key_clock;
  int fall_time = 1.5;

  window -> clear(); //można podać kolor
  //game loop
  while (window->isOpen()){
    if (!this->paused){
    while (game_clock.getElapsedTime() < sf::seconds(fall_time)){
      event_handling();
      window -> clear(); //można podać kolor
      window -> draw(*piece);
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
              this->paused = false;
            }
        }
      }
    }
  }
}
