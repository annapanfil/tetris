//kompilacja g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
// #include "board.hpp"
// #include "piece.hpp"

#include "game.hpp"

int main(){
  Game game;
  game.start();
  return 0;
}
