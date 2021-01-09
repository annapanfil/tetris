#include "stack.hpp"

Stack::Stack(Board* board):Shape(board->get_heigth(), board->get_width(), board){
  this -> color = sf::Color::Red;
  this -> heigth = 0;
  this -> width = board->get_width()/board->get_pixel();
}

void Stack::add(Piece* piece, int field){
 std::cout<<"add\n";
 for (int row=piece->shape.size()-1; row>=0; row--){
   std::vector<bool> new_line(width, 0);
   std::cout<<std::endl;
   for (int col=0; col<piece->shape[row].size(); col++){
     // std::cout<<row<<" "<<col<<std::endl;
     if(piece->shape[row][col]==1){
       // std::cout<<"here\n";
       new_line[field+col] = 1;
     }
   }
   this->shape.push_back(new_line);
   this->heigth ++;
 }
 std::cout<<"size: "<<shape.size()<<" "<<shape[0].size()<<" heigth: "<<heigth<<std::endl;
 for (int i = shape.size()-1; i>=0; i--)
 {for (int j=0; j<shape[i].size(); j++){
   // std::cout<<i<<" "<<j<<std::endl;
   std::cout<<shape[i][j]<<" ";
 }
    std::cout<<std::endl;}
}


void Stack::remove_full_lines(){

}

// bool Stack::check


bool Stack::check_collision(Piece* piece){
  if(piece->get_bottom() >= get_border()){
    int field = piece->get_left()/board->get_pixel();
    if (this->heigth == 0 || this->shape.back()[field] == 1){ //TODO: albo następne pola klocka
      std::cout<<"stack_collision "<< this-> heigth<<std::endl;
      this -> add(piece, field);
      this -> remove_full_lines();
      return true;
    }
    else{
      std::cout<<"not stack_collision "<< this-> heigth<<std::endl;
      return false;
    }
  }
}
