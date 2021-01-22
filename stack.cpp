#include "stack.hpp"

#define PIXEL board->get_pixel()

Stack::Stack(Board* board):Shape(board->get_width(), board->get_heigth(), board){
  this -> color = sf::Color::Red;
  this -> heigth = 0;
  this -> width = board->get_width()/PIXEL;
}

void Stack::draw(sf::RenderTarget& target, sf::RenderStates state) const{
  for(int row=shape.size()-1; row>=0; row--){
    for(int col=0; col<shape[row].size(); col++){
      if (shape[row][col] == 1){
        sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(PIXEL, PIXEL));
        rectangle.sf::Transformable::setPosition(col*PIXEL, position[1]-(row+1)*PIXEL);
        rectangle.sf::Shape::setFillColor(this->color);
        target.draw(rectangle);
      }
    }
  }
}

void Stack::add(Piece* piece, bool bottom){
  int fields_from_left = piece->get_left()/PIXEL;
  int stack_line;
  if (bottom) stack_line = 0;
  else stack_line = ((board->get_heigth() - piece->get_bottom())/PIXEL)+1; //one line higher
  for (int row=piece->shape.size()-1; row>=0; row--){    //each line of piece
    if(stack_line > heigth-1){  //new stack line
      std::vector<bool> new_line(width, 0);
      this->shape.push_back(new_line);
      this->heigth++;
    }
    for (int col=0; col<piece->shape[row].size(); col++){  //add line of piece to stack
      if (piece->shape[row][col]==1){
        shape[stack_line][col+fields_from_left] = 1;
      }
    }
    stack_line++;
  }
}

bool full_line(std::vector<bool> line){
  for (bool field : line){
    if (field == 0){
      return 0;
    }
  }
  return 1;
}

void Stack::remove_full_lines(){
  for (std::vector<std::vector<bool>>::iterator line=shape.begin(); line != shape.end(); line++){
    if(full_line(*line)){
      shape.erase(line);
      heigth--;
    }
  }
}


bool Stack::check_whole_piece(Piece* piece){
    int fields_from_left = piece->get_left()/PIXEL;
    int stack_line = (board->get_heigth() - piece->get_bottom())/PIXEL;
    for (int row=piece->shape.size()-1; row>=0; row--){    //each line of piece
      if (stack_line < heigth){ //stack is here
      for (int col=0; col<piece->shape[row].size(); col++){
        if (piece->shape[row][col]==1){
          if (this->shape[stack_line][fields_from_left + col] == 1) //is there stack field below piece field?
            return true;
        }
      }
    }
    stack_line++;
  }
  return false;
}


bool Stack::check_collision(Piece* piece){
  //TODO: very ugly solution. CHANGE IT!
  if(check_whole_piece(piece)){   //hit the stack
    this -> add(piece, false);
    this -> remove_full_lines();
    return true;
  }
  else if(piece->get_bottom() >= board->get_heigth()){   //hit the bottom
    this -> add(piece, true);
    this -> remove_full_lines();
    return true;
  }
  else{
    return false;
  }
}

bool Stack::check_collision_horizontally(Piece* piece, int direction){
  int fields_from_left = direction < 0 ? piece->get_left()/PIXEL : piece->get_right()/PIXEL-1;
  int stack_line = (board->get_heigth() - piece->get_bottom())/PIXEL;
  for (int row=piece->shape.size()-1; row>=0; row--){    //each line of piece
    if (stack_line < heigth){ //stack is here
      int field_to_check = direction < 0 ? piece->shape[row][0] : piece->shape[row].back();
      if (field_to_check == 1){
        if (this->shape[stack_line][fields_from_left] == 1) //is there stack field below piece field?
          return true;
      }
    }
  stack_line++;
  }
  return false;
}
