#pragma once
#include "shape.hpp"

class Piece: public Shape{
    std::vector<std::vector<bool>> shape;
    std::vector<std::vector<bool>> random_shape();
public:
    std::vector<sf::RectangleShape*> visual;
    Piece(int x, int y, const int PIXEL); //TODO: from board
  // bool wall_collision();
  // bool stack_collision(Stack stack);
  // void move_horizontally(int movement);
  // void move_down();
  // void rotate(char direction);
};
