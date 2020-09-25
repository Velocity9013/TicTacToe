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
	void setTile(char content, int row, int column);

	char board[3][3];
	sf::Sprite sprites[3][3];

	sf::Texture backgroundTexture;
	sf::Texture xTexture;
	sf::Texture oTexture;
	sf::Texture blankTexture;

	sf::Sprite background;
};