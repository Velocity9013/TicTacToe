#include <TicTacToe/Board.hpp>

#include <iostream>

Board::Board()
{
	backgroundTexture.loadFromFile("resources/board.png");
	background.setTexture(backgroundTexture);

	xTexture.loadFromFile("resources/x.png");
    oTexture.loadFromFile("resources/o.png");

    for(int row = 0; row < 3; row++){
    	for(int column = 0; column < 3; column++){
    		board[row][column] = '-';
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
    if(board[row][column] == '-'){
        (content == 'x') ? board[row][column] = 'x' : board[row][column] = 'o';
        sprites[row][column].setTexture((content == 'x') ? xTexture : oTexture, true);
    }
	if(content == '-'){
		sprites[row][column].setTexture(blankTexture, true);
	}
}

void Board::getResult()
{
	
    int counter = 0;
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            counter++;
            std::cout << " | " << board[row][column];

            if(counter % 3 == 0){
                std::cout << " | " << std::endl;
            }
        }
    }
    
    int evaluateScore = evaluateWinner();
    
    std::cout << evaluateScore << std::endl;

    if((isFull() && evaluateScore == 0) || evaluateScore == -10 || evaluateScore == 10){
        if(isFull() && evaluateScore == 0){
            std::cout << "Tie!" << std::endl;
        }
        else if(evaluateScore == -10){
            std::cout << "Player Wins!" << std::endl;
        }
        else if(evaluateScore == +10){
            std::cout << "Ai Wins!" << std::endl;
        }
        std::cout << "Game Reset" << std::endl << std::endl;
        reset();
    }	
}

void Board::reset()
{
	for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            board[row][column] = '-';
            setTile('-', row, column);
        }
    }
}

void Board::makeMove(int player, int row, int column)
{
	setTile((player == 0) ? 'o' : 'x', row, column);
}

bool Board::isFull() const
{
	for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(board[row][column] == '-'){
                return false;
            }
        }
    }
    return true;
}

int Board::evaluateWinner() const
{
	for(int row = 0; row < 3; row++){
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2]){
            if(board[row][0] == 'x'){
                return -10;
            }
            else if(board[row][0] == 'o'){
                return +10;
            }
        }
    }
    
    for(int column = 0; column < 3; column++){
        if(board[0][column] == board[1][column] && board[1][column] == board[2][column]){ 
            if (board[0][column] == 'x'){
                return -10; 
            }
            else if (board[0][column] == 'o'){
                return +10; 
            }
        }
    }
    
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[0][0] == 'x'){
                return -10;
        }
        else if(board[0][0] == 'o'){
            return +10;
        }
    }
    
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[0][2] == 'x'){
                return -10;
        }
        else if(board[0][2] == 'o'){
            return +10;
        }
    }
    
    return 0;
}

int Board::minimax(bool depth, bool maximizingPlayer)
{
    int evaluateScore = evaluateWinner();
    if(evaluateScore == 10 || evaluateScore == -10){
        return evaluateScore;
    }

    if(isFull() && evaluateScore == 0){
        return 0;
    }
    
    if(maximizingPlayer){
        int value = std::numeric_limits<int>::max() * -1;

        for(int row = 0; row < 3; row++){
            for(int column = 0; column < 3; column++){
                //checking for all possibilities
                if(board[row][column] == '-'){
                    board[row][column] = 'o';
                    value = std::max(value, minimax(depth + 1, !maximizingPlayer));
                    board[row][column] = '-';
                }
            }
        }
        return value;
    }
    else{
        int value = std::numeric_limits<int>::max();
        
        for(int row = 0; row < 3; row++){
            for(int column = 0; column < 3; column++){
                //checking for all possibilities
                if(board[row][column] == '-'){
                    board[row][column] = 'x';
                    value = std::min(value, minimax(depth + 1, !maximizingPlayer));
                    board[row][column] = '-';
                }
            }
        }
        return value;
    }
}

void Board::aiOptimalMove(std::pair<int, int> makeAiMove){
    int value = std::numeric_limits<int>::max() * - 1;

    makeAiMove = std::make_pair(-1, -1);
    
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(board[row][column] == '-'){
                board[row][column] = 'o';
                int tempValue = minimax(0, false);
                board[row][column] = '-';

                if(value < tempValue){   
                    makeAiMove.first = row;
                    makeAiMove.second = column;
                    value = tempValue; 
                }   
            }
        }
    }
    
    setTile(1, makeAiMove.first, makeAiMove.second);
}