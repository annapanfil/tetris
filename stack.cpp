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

void Stack::add(Piece* piece){
  // std::cout<<"add\n";
  int fields_from_left = piece->get_left()/PIXEL;
  int stack_line = (board->get_heigth() - piece->get_bottom())/PIXEL;
  if (stack_line<0) stack_line = 0;
  // std::cout<<"line "<<stack_sline<<"board "<<board->get_heigth()<<"piece "<<piece->get_bottom()<<"pixel "<<PIXEL<<std::endl;
  for (int row=piece->shape.size()-1; row>=0; row--){    //each line of piece
    // std::cout<<"here\n";
    if(stack_line > heigth-1){  //new stack line

      // std::cout<<"add new line\n";
      std::vector<bool> new_line(width, 0);
      this->shape.push_back(new_line);
      this->heigth ++;
    }
    // std::cout<<"there\n";
    for (int col=0; col<piece->shape[row].size(); col++){  //add line of piece to stack
      if (piece->shape[row][col]==1){
        // std::cout<<"add to stack\n";
        shape[stack_line][col+fields_from_left] = 1;
      }
    }
    // std::cout<<row<<" "<<col<<std::endl;
    stack_line++;
    // std::cout<<"end\n";
  }
  std::cout<<"size: "<<shape.size()<<" "<<shape[0].size()<<" heigth: "<<heigth<<std::endl;
  for (int i = shape.size()-1; i>=0; i--){
    for (int j=0; j<shape[i].size(); j++){
      // std::cout<<i<<" "<<j<<std::endl;
      std::cout<<shape[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}


void Stack::remove_full_lines(){

}


bool Stack::check_whole_piece(Piece* piece){
    std::cout<<"check\n";
    int fields_from_left = piece->get_left()/PIXEL;
    int stack_line = (board->get_heigth() - piece->get_bottom())/PIXEL - 1;
    for (int row=piece->shape.size()-1; row>=0; row--){    //each line of piece
      if (stack_line < heigth){ //stack is here
      for (int col=0; col<piece->shape[row].size(); col++){
        if (piece->shape[row][col]==1){
          // std::cout<<"check stack\n";
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
  if(piece->get_bottom() >= board->get_heigth() || check_whole_piece(piece)){
    // std::cout<<"stack_collision "<< this-> heigth<<std::endl;
    this -> add(piece);
    this -> remove_full_lines();
    return true;
  }
  else{
    // std::cout<<"not stack_collision "<< this-> heigth<<std::endl;
    return false;
  }
}

bool Stack::check_collision_horizontally(Piece* piece, int direction){
  std::cout<<"check horizontally\n";
  int fields_from_left = piece->get_left()/PIXEL;
  int stack_line = (board->get_heigth() - piece->get_bottom())/PIXEL;
  for (int row=piece->shape.size()-1; row>=0; row--){    //each line of piece
    std::cout<<"check if stack\n";
    if (stack_line < heigth){ //stack is here
      // std::cout<<"check if pieces " <<row<<std::endl;
      if (piece->shape[row][0]==1){
        std::cout<<"check stack "<<row<<" "<<stack_line<<" "<<fields_from_left<<std::endl;
        if (this->shape[stack_line][fields_from_left] == 1) //is there stack field below piece field?
          return true;
      }
    }
  stack_line++;
  // std::cout<<"end\n";
  }
  return false;
}
