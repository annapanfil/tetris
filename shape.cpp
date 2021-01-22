#include "shape.hpp"
#include <SFML/Graphics.hpp>

Shape::Shape(int x, int y, Board* _board): board(_board){
  this -> position[0] = x-board->get_pixel();
  this -> position[1] = y;
}
