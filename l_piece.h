#ifndef TETRIS_LPIECE_H
#define TETRIS_LPIECE_H
#include "piece.hpp"

class L_piece: public Piece{
  bool shape[3][2] = {{1,1}, {0,1}, {0,1}};
public:
  sf::RectangleShape* visual = new sf::RectangleShape(sf::Vector2f(10, 10));
};

#endif //TETRIS_LPIECE_H
