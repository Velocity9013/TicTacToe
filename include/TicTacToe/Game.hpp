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
};