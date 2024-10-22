#pragma once
#include "shape.hpp"
#include "piece.hpp"

class Stack: public Shape{
  int width;
public:
  int heigth;
  Stack(Board* board);
  bool check_collision(Piece* piece); //TODO: check stack collision horizontally
  bool check_collision_horizontally(Piece* piece, int direction);
  bool check_whole_piece(Piece* piece);
  void add(Piece* piece, bool bottom);
  int get_border() const {return board->get_heigth() - this->heigth*board->get_pixel();}
  void remove_full_lines();
  void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};
