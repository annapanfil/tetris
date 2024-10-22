#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cmath>

#include "piece.hpp"
#include "stack.hpp"

#define PIXEL board->get_pixel()

using std::cout;
using std::endl;

Piece::Piece(Board* board):Shape(floor(((board->get_width())-PIXEL)/(2*PIXEL))*PIXEL,0,  board){
  this -> random_shape();
  this -> color = sf::Color::Green;
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates state) const{
  for(int row=0; row<shape.size(); row++){
    for(int col=0; col<shape[row].size(); col++){
      if (shape[row][col] == 1){
        sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(board->get_pixel(), board->get_pixel()));
        rectangle.sf::Transformable::setPosition(this->position[0]+col*board->get_pixel(), this->position[1]+row*board->get_pixel());
        rectangle.sf::Shape::setFillColor(this->color);
        target.draw(rectangle);
      }
    }
  }
}

void Piece::random_shape(){
    srand (time(NULL));
    int choice = rand() % 7;
    this->shape = {{},{}};

    switch(choice){
    case 0: //J
      shape[0].insert(shape[0].end(),{1,1,1});
      shape[1].insert(shape[1].end(),{0,0,1}); break;
    case 1: //T
      shape[0].insert(shape[0].end(),{1,1,1});
      shape[1].insert(shape[1].end(),{0,1,0}); break;
    case 2: //O
      shape[0].insert(shape[0].end(),{1,1});
      shape[1].insert(shape[1].end(),{1,1}); break;
    case 3: //L
      shape[0].insert(shape[0].end(),{0,0,1});
      shape[1].insert(shape[1].end(),{1,1,1}); break;
    case 4: //S
      shape[0].insert(shape[0].end(),{0,1,1});
      shape[1].insert(shape[1].end(),{1,1,0}); break;
    case 5: //Z
      shape[0].insert(shape[0].end(),{1,1,0});
      shape[1].insert(shape[1].end(),{0,1,1}); break;
    case 6: //I
      shape[0].insert(shape[0].end(),{1,1,1,1});
      rotate_clockwise(); rotate_clockwise(); break;
    }
}

void Piece::move(int dx, int dy, Stack* stack = nullptr){
  dx *= PIXEL;
  dy *= PIXEL;
  this -> position[0] += dx;
  this -> position[1] += dy;
  if (this -> wall_collision()){
    this -> position[0] -= dx; //undo
    this -> position[1] -= dy;
  }
  else if(stack != nullptr && stack->check_collision_horizontally(this, dx)){
    this -> position[0] -= dx;
  }
}

void Piece::move_down(){
  this -> move(0, 1);
}

void Piece::move_horizontally(int direction, Stack* stack){
    this -> move(direction, 0, stack);
}

bool Piece::wall_collision(){

  if (get_left()<0 || get_right()>board->get_width() || get_bottom() > board->get_heigth()){
    return true;
  }
  else{
    return false;
  }
}

void Piece::rotate_clockwise(){
  vector<vector<bool>> rotated_shape(shape[0].size(), vector<bool>());

  //transpose
  for (int i = 0; i<shape.size(); i++)
    for (int j=0; j<shape[i].size(); j++)
      rotated_shape[j].push_back(shape[i][j]);

  //mirror vertically
  for (int i = 0; i<rotated_shape.size(); i++)
    std::reverse(rotated_shape[i].begin(), rotated_shape[i].end());

  this -> shape = rotated_shape;
}

void Piece::rotate_counterclockwise(){
  vector<vector<bool>> rotated_shape(shape[0].size(), vector<bool>());

  //mirror vertically
  for (int i = 0; i<shape.size(); i++)
    std::reverse(shape[i].begin(), shape[i].end());

  //transpose
  for (int i = 0; i<shape.size(); i++)
    for (int j=0; j<shape[i].size(); j++)
      rotated_shape[j].push_back(shape[i][j]);

  this -> shape = rotated_shape;

}
