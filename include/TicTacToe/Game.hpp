#pragma once

#include <SFML/Graphics.hpp>

class Game{
public:
	Game();

	void run();

private:
	sf::RenderWindow window;
	sf::Texture x_texture;
	sf::Texture o_texture;
	sf::Sprite x_sprite;
	sf::Sprite o_sprite;
};