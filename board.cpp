#include "board.hpp"

Board::Board(int x, int y, int _pixel): pixel(_pixel){
  this -> size [0] = x;
  this -> size [1] = y;
}
