#pragma once
#include "board.hpp"
#include "piece.hpp"

class Game{
  sf::RenderWindow* window;
  Board* board;
  Piece* piece;
  int score = 0;
  int speed;
  bool paused = false;
public:
  Game();
  void start();
  // void pause();
  // void end();
  // void increase_speed();
  void event_handling();
  void increment_score(int points=1){score += points;}
};
