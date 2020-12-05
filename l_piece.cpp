#include "l_piece.hpp"

L_piece::L_piece(int x, int y, const int PIXEL){
  this -> position[0] = x;
  this -> position[1] = y;
  for(int col=0; col<3; col++){
    for(int row=0; row<2; row++){
      if (shape[row][col] == 1){
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(PIXEL, PIXEL));
        rectangle -> sf::Transformable::setPosition(x+(col-1)*PIXEL, y+row*PIXEL);
        rectangle -> sf::Shape::setFillColor(sf::Color::Green);
        this -> visual.push_back(rectangle);
      }
    }
  }

}
