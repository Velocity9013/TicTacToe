#include <TicTacToe/Game.hpp>

Game::Game()
:   window(sf::VideoMode(600, 600), "TicTacToe!")
{
    x_texture.loadFromFile("resources/x.png");
    o_texture.loadFromFile("resources/o.png");

    x_sprite.setTexture(x_texture);
    x_sprite.setPosition(sf::Vector2f(200.f, 200.f));
    o_sprite.setTexture(o_texture);
    o_sprite.setPosition(sf::Vector2f(400.f, 200.f));
}

void Game::run(){
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
                window.close();
                break;
            }
        }

        window.clear(sf::Color(240, 240, 255));
        window.draw(board);
        window.draw(x_sprite);
        window.draw(o_sprite);
        window.display();
    }
}