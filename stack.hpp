#pragma once
#include "shape.hpp"
#include "piece.hpp"

class Stack: public Shape{
  int width;
public:
  int heigth;
  Stack(Board* board);
  bool check_collision(Piece* piece); //TODO
  void add(Piece* piece, int field); //TODO
  int get_border() const {return board->get_heigth() - this->heigth*board->get_pixel();}
  void remove_full_lines(); //TODO
  void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};
