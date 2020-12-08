#pragma once
#include "shape.hpp"

class Piece: public Shape, public sf::Drawable{
    vector<vector<bool>> shape;
    vector<vector<bool>> random_shape();
    void move(int dx, int dy);
public:
    vector<sf::RectangleShape*> visual;
    Piece(int x, int y, Board* Board);
    bool wall_collision();
    // bool stack_collision(Stack stack);
    void move_horizontally();
    void move_down();
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
    // void rotate(char direction);
};
