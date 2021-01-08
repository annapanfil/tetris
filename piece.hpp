#pragma once
#include "shape.hpp"
#include <iostream>

class Piece: public Shape{
    vector<vector<bool>> random_shape();
    void move(int dx, int dy);
public:
    ~Piece() {std::cout << "destructor" << '\n';}
    Piece(int x, int y, Board* board);
    bool wall_collision();
    void move_horizontally(int direction);
    void move_down();
    void rotate_clockwise();
    void rotate_counterclockwise();
    int get_top(){return position[1];}
    int get_left(){return position[0];}
    int get_bottom(){return position[1]+(shape.size()*board->get_pixel());}
    int get_right(){return position[0]+(shape[0].size()*board->get_pixel());}
};
