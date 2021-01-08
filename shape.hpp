#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "board.hpp"

using std::vector;

class Shape{
  vector<vector<bool>> matrix;
protected:
  int position[2]; //left top
  Board* board;
  Shape(int x, int y, Board* board);
public:
  int get_top(){return position[1];}
  int get_left(){return position[0];}
  int get_bottom(int heigth){return position[1]+(heigth*board->get_pixel());}
  int get_right(int widht){return position[0]+(widht*board->get_pixel());}
  // virtual void check() = 0;
};
