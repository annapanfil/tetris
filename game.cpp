#include "game.hpp"

Game::Game(){
  const int PIXEL = 20;
  this -> window = new sf::RenderWindow (sf::VideoMode(400,600), "Tetris", sf::Style::Close | sf::Style::Titlebar); //TODO: from board dimensions //sf::Style::Close || sf::Style::Titlebar
  this -> window -> setFramerateLimit(5);
  this -> board = new Board (400, 600, PIXEL);
  this -> piece = new Piece((400-PIXEL)/2,0, this->board);
}

void Game::event_handling(){
  sf::Event event;
  while (window -> pollEvent(event))
  //process events
  switch(event.type){
    case sf::Event::Closed:
      window -> close(); break;
    // case sf::Event::Resized:
    //   std::cout<<event.size.width;
  }
}


void Game::start(){
  // sf::Clock clock;
  // sf::Time timeSinceLastUpdate;
  // sf::Time TimePerFrame = sf::seconds(1.f/60);

  //game loop
  while (window->isOpen()){
      event_handling();
      // timeSinceLastUpdate = clock.restart();
      // while (timeSinceLastUpdate > TimePerFrame){
      //     timeSinceLastUpdate -= TimePerFrame;
      //     update(TimePerFrame);
      // }

    window -> clear(); //można podać kolor
    window -> draw(*piece);
    window -> display();
    // // sf::sleep(sf::milliseconds(170)); //TODO: sf::clock
    piece->move_down();
    piece->move_horizontally();
  }
}
