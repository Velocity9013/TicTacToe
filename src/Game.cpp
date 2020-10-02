#include <TicTacToe/Game.hpp>

Game::Game()
:   window(sf::VideoMode(600, 600), "TicTacToe!")
{
    srand (time(NULL));
    playerOrAi = rand() % 2;
}

void Game::run(){
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
                window.close();
                break;
            }

            if(event.type == sf::Event::MouseButtonPressed){
                board.makeMove(playerOrAi, event.mouseButton.y / 200, event.mouseButton.x / 200);
                playerOrAi = !playerOrAi;

                board.getResult();
            }
        }

        window.clear(sf::Color(240, 240, 255));
        window.draw(board);
        window.display();
    }
}