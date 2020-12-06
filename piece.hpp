#pragma once
#include "shape.hpp"

class Piece: public Shape{
    vector<vector<bool>> shape;
    vector<vector<bool>> random_shape();
public:
    vector<sf::RectangleShape*> visual;
    Piece(int x, int y, const int PIXEL); //TODO: from board
  // bool wall_collision();
  // bool stack_collision(Stack stack);
  // void move_horizontally(int movement);
  void move_down(int PIXEL);
  // void rotate(char direction);
};
