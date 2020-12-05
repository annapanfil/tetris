//kompilacja g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "l_piece.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 600), "Tetris");
    L_piece l_piece;

   while (window.isOpen())
    {
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }

        window.clear();
        window.draw(*l_piece.visual);
        window.display();
    }

    return 0;
}
