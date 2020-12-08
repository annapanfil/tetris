#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "piece.hpp"

Piece::Piece(int x, int y, const int PIXEL){
  this -> shape = random_shape();
  this -> position[0] = x;
  this -> position[1] = y;
  this -> PIXEL = PIXEL;

  for(int row=0; row<2; row++){
    for(int col=0; col<3; col++){
      if (shape[row][col] == 1){
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(PIXEL, PIXEL));
        rectangle -> sf::Transformable::setPosition(x+(col-1)*PIXEL, y+row*PIXEL);
        rectangle -> sf::Shape::setFillColor(sf::Color::Green);
        this -> visual.push_back(rectangle);
      }
    }
  }
}


vector<vector<bool>> Piece::random_shape(){
    srand (time(NULL));
    int choice = rand() % 1;
    vector<vector<bool>> shape = {{},{}};

    switch(choice){

    case 0: //L
      shape[0].insert(shape[0].end(),{1,1,1});
      shape[1].insert(shape[1].end(),{0,0,1}); break;
    }
    return shape;
}


void Piece::draw(sf::RenderTarget& target, sf::RenderStates state) const{
  for (auto square: this->visual)
    target.draw(*square);
}

void Piece::move(int dx, int dy){
  this -> position[0] += dx;
  this -> position[1] += dy;
  for (auto square: this->visual)
      square -> sf::Transformable::move(dx, dy);
}

void Piece::move_down(){
  this -> move(0, PIXEL);
}

void Piece::move_horizontally(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) //&& o nic nie uderzy
    this -> move(-PIXEL, 0);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) //&& o nic nie uderzy
    this -> move(PIXEL, 0);
}
