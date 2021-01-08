#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "piece.hpp"

using std::cout;
using std::endl;

Piece::Piece(int x, int y, Board* board):Shape(x,y, board){
  this -> shape = random_shape();
  this -> color = sf::Color::Green;
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

void Piece::move(int dx, int dy){
  dx *= board->get_pixel();
  dy *= board->get_pixel();
  this -> position[0] += dx;
  this -> position[1] += dy;
  if (this -> wall_collision()){ //cofnij
    this -> position[0] -= dx;
    this -> position[1] -= dy;
  }
}

void Piece::move_down(){
  this -> move(0, 1);
}

void Piece::move_horizontally(int direction){
    this -> move(direction, 0);
}

bool Piece::wall_collision(){

  if (get_bottom()>board->get_heigth() || get_left()<0 || get_right()>board->get_width()){
    return true;
  }
  else{
    return false;
  }
}

void Piece::rotate_clockwise(){
  // cout<<"rotate_clockwise\n";
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
  // cout<<"rotate_counterclockwise\n";
  vector<vector<bool>> rotated_shape(shape[0].size(), vector<bool>());

  //mirror vertically
  for (int i = 0; i<shape.size(); i++)
    std::reverse(shape[i].begin(), shape[i].end());

  //transpose
  for (int i = 0; i<shape.size(); i++)
    for (int j=0; j<shape[i].size(); j++)
      rotated_shape[j].push_back(shape[i][j]);

  // for (int i = 0; i<shape.size(); i++)
  //   {for (int j=0; j<shape[i].size(); j++)
  //     cout<<shape[i][j]<<" ";
  //   cout<<endl;}

  this -> shape = rotated_shape;

}
