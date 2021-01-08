#pragma once
#include <iostream>

class Board{
  int size[2];
  int pixel;
public:
  Board(int x, int y, int pixel);
  void show();
  int get_pixel(){return pixel;}
  int get_width(){return size[0];}
  int get_heigth(){return size[1];}
};
