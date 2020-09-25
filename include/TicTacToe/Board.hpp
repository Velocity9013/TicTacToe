#pragma once

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable
{
public:
	Board();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void reset();
	void makeMove(int player, int row, int column);
	bool isFull() const; 
	int evaluateWinner() const;


private:
	char board[3][3];

	sf::Texture backgroundTexture;
	sf::Sprite background;
};