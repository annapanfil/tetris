#pragma once
#include <iostream>

class Board{
  int size[2];
  int pixel;
public:
  Board(int x, int y, int pixel);
  int get_pixel(){return pixel;}
  int get_width(){return size[0];}
  int get_heigth(){return size[1];}
};
