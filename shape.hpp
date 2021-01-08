#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "board.hpp"

using std::vector;

class Shape: public sf::Drawable{
protected:
  vector<vector<bool>> shape;
  sf::Color color;
  int position[2]; //left top in piece, right bottom in stack
  Board* board;
  Shape(int x, int y, Board* board);
public:
  void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};
