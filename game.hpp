#pragma once
#include "board.hpp"
#include "piece.hpp"
#include "stack.hpp"

class Game{
  sf::RenderWindow* window;
  Board* board;
  Piece* piece;
  Stack* stack;
  bool paused = false;
public:
  Game();
  void introduce();
  void display_text(std::string);
  void start();
  void update();
  void display_all();
  void pause_menu(sf::RenderWindow*);
  void finish();
  void event_handling();
};
