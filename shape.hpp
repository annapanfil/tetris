#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

using std::vector;

class Shape{
  vector<vector<bool>> matrix;
protected:
  int position[2];
public:
  // sf::RectangleShape* show();
  // virtual void check() = 0;
};
