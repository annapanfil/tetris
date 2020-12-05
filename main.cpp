//kompilacja g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "l_piece.hpp"

const int PIXEL = 20; //TODO: in board

int main()
{
    sf::RenderWindow window(sf::VideoMode(400,600), "Tetris"); //TODO: from board dimensions
    L_piece l_piece((400-PIXEL)/2,0, PIXEL);

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
