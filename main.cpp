//kompilacja g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "piece.hpp"

const int PIXEL = 20; //TODO: in board

int main()
{
    sf::RenderWindow window(sf::VideoMode(400,600), "Tetris"); //TODO: from board dimensions
    window.setFramerateLimit(5);
    Piece piece((400-PIXEL)/2,0, PIXEL);

   while (window.isOpen())
    {
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }

        window.clear();
        window.draw(piece);
        window.display();
        // sf::sleep(sf::milliseconds(170)); //TODO: sf::clock
        piece.move_down();
        piece.move_horizontally();
    }

    return 0;
}
