#pragma once
class Game{
  board Board;
  int score = 0;
  int speed;
  enum controls {LEFT, RIGHT, UP, DOWN};
  // keys[4]
  bool paused = False;
public:
  void start();
  void pause();
  void end();
  void increase_speed();
  void increment_score(int points=1){score += points;}
};
