#include <TicTacToe/Board.hpp>

Board::Board()
{
	backgroundTexture.loadFromFile("resources/board.png");
	background.setTexture(backgroundTexture);

	xTexture.loadFromFile("resources/x.png");
    oTexture.loadFromFile("resources/o.png");

    for(int row = 0; row < 3; row++){
    	for(int column = 0; column < 3; column++){
    		sprites[row][column] = sf::Sprite(blankTexture);
    		sprites[row][column].setPosition(sf::Vector2f(column * 200.f, row * 200.f));
    	}
    }
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
	for(int row = 0; row < 3; row++){
    	for(int column = 0; column < 3; column++){
 			target.draw(sprites[row][column]);   		
    	}
    }
}

void Board::setTile(char content, int row, int column)
{
	board[row][column] = content;
	if(content == '-'){
		sprites[row][column].setTexture(blankTexture);
	}
	else{
		sprites[row][column].setTexture((content == 'x') ? xTexture : oTexture, true);
	}
}

void Board::reset()
{
	for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            board[row][column] = '-';
        }
    }
}

void Board::makeMove(int player, int row, int column)
{
	setTile((player == 0) ? 'x' : 'o', row, column);
}

bool Board::isFull() const
{
	return true;
}

int Board::evaluateWinner() const
{
	
}
