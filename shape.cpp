#include "shape.hpp"
#include <SFML/Graphics.hpp>

Shape::Shape(int x, int y, Board* _board): board(_board){
  this -> position[0] = x-board->get_pixel();
  this -> position[1] = y;
}

//
// sf::RectangleShape* Shape::show() {
//     sf::RectangleShape rect(sf::Vector2f(1, 1));
//     rect.setFillColor(sf::Color::Green);
//     return &rect;
// }
