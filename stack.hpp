#pragma once
#include "shape.hpp"
#include "piece.hpp"

class Stack: public Shape{
public:
  void check() override;
  bool remove_full_lines();
  bool check_gameover();
  void add(Piece piece);
};
