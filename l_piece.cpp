#include "l_piece.hpp"

L_piece::L_piece(int x, int y, const int PIXEL){
  this -> position[0] = x;
  this -> position[1] = y;
  this -> visual = new sf::RectangleShape(sf::Vector2f(PIXEL, PIXEL));
  visual -> sf::Transformable::setPosition(x,y);
  visual -> sf::Shape::setFillColor(sf::Color::Green);
}
