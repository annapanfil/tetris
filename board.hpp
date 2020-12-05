#pragma once
class Board{
  int size[2];
  Piece curr_piece;
  Piece next_piece;
public:
  void show();
  void set_size(int x, int y){size = [x,y];}
  void insert_random_piece();
};
