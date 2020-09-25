#pragma once

#include <TicTacToe/Board.hpp>

#include <SFML/Graphics.hpp>

class Game{
public:
	Game();

	void run();

private:
	sf::RenderWindow window;

	Board board;

	sf::Texture x_texture;
	sf::Texture o_texture;

	sf::Sprite x_sprite;
	sf::Sprite o_sprite;
};