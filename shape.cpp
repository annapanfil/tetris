#include "shape.hpp"
#include <SFML/Graphics.hpp>

Shape::Shape(int x, int y, Board* _board): board(_board){
  this -> position[0] = x-board->get_pixel();
  this -> position[1] = y;
}


void Shape::draw(sf::RenderTarget& target, sf::RenderStates state) const{
  for(int row=0; row<shape.size(); row++){
    for(int col=0; col<shape[row].size(); col++){
      if (shape[row][col] == 1){
        sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(board->get_pixel(), board->get_pixel()));
        rectangle.sf::Transformable::setPosition(this->position[0]+col*board->get_pixel(), this->position[1]+row*board->get_pixel());
        rectangle.sf::Shape::setFillColor(sf::Color::Green);
        target.draw(rectangle);
      }
    }
  }
}

//
// sf::RectangleShape* Shape::show() {
//     sf::RectangleShape rect(sf::Vector2f(1, 1));
//     rect.setFillColor(sf::Color::Green);
//     return &rect;
// }
