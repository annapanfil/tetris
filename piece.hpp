#pragma once
#include "shape.hpp"
#include <iostream>

class Piece: public Shape, public sf::Drawable{
    vector<vector<bool>> shape;
    vector<vector<bool>> random_shape();
    void move(int dx, int dy);
public:
    ~Piece() {std::cout << "destructor" << '\n';}
    Piece(int x, int y, Board* Board);
    bool wall_collision();
    // bool stack_collision(Stack stack);
    void move_horizontally(int direction);
    void move_down();
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
    void rotate_clockwise();
    void rotate_counterclockwise();
};
