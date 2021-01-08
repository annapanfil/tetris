#include "stack.hpp"

Stack::Stack(Board* board):Shape(board->get_heigth(), board->get_width(), board){
  this -> color = sf::Color::Red;
  this -> heigth = 1;
}

void Stack::add(Piece* piece){
}

void Stack::remove_full_lines(){
  
}

bool Stack::check_collision(Piece* piece){
  if(piece->get_bottom() > get_border()){
    std::cout<<"stack_collision"<<std::endl;
    this -> add(piece);
    this -> remove_full_lines();
    return true;
  }
}
