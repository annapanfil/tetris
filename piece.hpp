#pragma once
#include "shape.hpp"

class Piece: public Shape, public sf::Drawable{
    vector<vector<bool>> shape;
    vector<vector<bool>> random_shape();
    int PIXEL;
public:
    vector<sf::RectangleShape*> visual;
    Piece(int x, int y, const int PIXEL); //TODO: from board
  // bool wall_collision();
  // bool stack_collision(Stack stack);
  void move_horizontally();
  void move_down();
  void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
  // void rotate(char direction);
};
