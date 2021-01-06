#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "piece.hpp"
using std::cout;
using std::endl;

Piece::Piece(int x, int y, Board* board):Shape(x,y, board){
  this -> shape = random_shape();

  for(int row=0; row<2; row++){
    for(int col=0; col<3; col++){
      if (shape[row][col] == 1){
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(board->get_pixel(), board->get_pixel()));
        rectangle -> sf::Transformable::setPosition(x+(col-1)*board->get_pixel(), y+row*board->get_pixel());
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
  dx *= board->get_pixel();
  dy *= board->get_pixel();
  this -> position[0] += dx;
  this -> position[1] += dy;
  if (!(this -> wall_collision())){
    for (auto square: this->visual)
      square -> sf::Transformable::move(dx, dy);
  }
  else{ //cofnij
    std::cout<<this->position[0]<<std::endl;
    this -> position[0] -= dx;
    this -> position[1] -= dy;
  }
}

void Piece::move_down(){
  this -> move(0, 1);
}

void Piece::move_horizontally(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    this -> move(-1, 0);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    this -> move(1, 0);
}

bool Piece::wall_collision(){
  if (get_bottom()>=board->get_heigth() || get_left()<=0 || get_right()>=board->get_width()){
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
}
