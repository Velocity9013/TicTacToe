#include <TicTacToe/Board.hpp>

Board::Board(){
	backgroundTexture.loadFromFile("resources/board.png");
	background.setTexture(backgroundTexture);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
}

void Board::reset()
{

}

void Board::makeMove(int player, int row, int column)
{

}

bool Board::isFull() const
{
	return true;
}

int Board::evaluateWinner() const
{
	return 0;
}
