#pragma once
#include "shape.hpp"
#include "piece.hpp"

class Stack: public Shape{
  int heigth;
public:
  Stack(Board* board);
  bool check_collision(Piece* piece); //TODO
  void add(Piece* piece); //TODO
  int get_border(){return board->get_heigth() - heigth;}
};
