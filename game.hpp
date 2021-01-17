#pragma once
#include "board.hpp"
#include "piece.hpp"
#include "stack.hpp"

class Game{
  sf::RenderWindow* window;
  Board* board;
  Piece* piece;
  Stack* stack;
  int score = 0;
  int speed;
  bool paused = false;
public:
  Game();
  void introduce();
  void display_text(sf::Font*, std::string);
  void start();
  void update();
  void finish(); //TODO
  // void increase_speed();
  void event_handling();
  void increment_score(int points=1){score += points;}
};
