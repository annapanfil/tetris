#pragma once
#include "board.hpp"
#include "piece.hpp"
#include "stack.hpp"

class Game{
  sf::RenderWindow* window;
  Board* board;
  Piece* piece;
  Stack* stack;
  // int score = 0;
  bool paused = false;
public:
  Game();
  void introduce();
  void display_text(std::string);
  void start();
  void update();
  void pause_menu(sf::RenderWindow*);
  void finish();
  void event_handling();
  // void increment_score(int points=1){score += points;}
};
