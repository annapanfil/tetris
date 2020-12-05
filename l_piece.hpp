#ifndef TETRIS_LPIECE_H
#define TETRIS_LPIECE_H
#include "piece.hpp"

class L_piece: public Piece{
  bool shape[2][3] = {{1,1,1}, {0,0,1}};
public:
  L_piece(int x, int y, const int PIXEL); //TODO: from board
  std::vector<sf::RectangleShape*> visual;
};

#endif //TETRIS_LPIECE_H
