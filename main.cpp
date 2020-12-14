//kompilacja g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"
#include "piece.hpp"

const int PIXEL = 20; //TODO: in board

int main()
{
    //create window, board & pieces
    sf::RenderWindow window(sf::VideoMode(400,600), "Tetris", sf::Style::Close | sf::Style::Titlebar); //TODO: from board dimensions //sf::Style::Close || sf::Style::Titlebar
    window.setFramerateLimit(5);
    Board board(400,600, PIXEL);
    Piece piece((400-PIXEL)/2,0, &board);
    //clock
    // sf::Clock clock;
    // sf::Time timeSinceLastUpdate;
    // sf::Time TimePerFrame = sf::seconds(1.f/60);

    //game loop
    while (window.isOpen()){
      sf::Event event;
      while (window.pollEvent(event))
      {
        //process events
        switch(event.type){
          case sf::Event::Closed:
            window.close(); break;
          // case sf::Event::Resized:
          //   std::cout<<event.size.width;
        }
        // timeSinceLastUpdate = clock.restart();
        // while (timeSinceLastUpdate > TimePerFrame){
        //     timeSinceLastUpdate -= TimePerFrame;
        //     update(TimePerFrame);
        // }

    }

    window.clear(); //można podać kolor
    window.draw(piece);
    window.display();
    // sf::sleep(sf::milliseconds(170)); //TODO: sf::clock
    piece.move_down();
    piece.move_horizontally();
    }

    return 0;
}
