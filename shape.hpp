#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Shape{
  std::vector<std::vector<bool>> matrix;
  int position[2];
public:
  // sf::RectangleShape* show();
  // virtual void check() = 0;
};
