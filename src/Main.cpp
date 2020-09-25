// #include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <limits>
#include <utility>
#include <time.h>

const char playerX = 'x';
const char aiO = 'o';

void resetBoard(char board[3][3]){
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            board[row][column] = '-';
        }
    }
}

void drawBoard(char board[3][3]){
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
}

void movesMake(char board[3][3], int row, int column, int playerOrAi){
    if(playerOrAi == 0){
        if(board[row][column] == '-'){
            board[row][column] = playerX;   
        }else{
            std::cout << "Turn Lost, Value aready exists here" << std::endl;
        }
    }
    else if(playerOrAi == 1){
        board[row][column] = aiO;   
    }
}

bool movesLeft(char board[3][3]){
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(board[row][column] == '-'){
                return true;
            }
        }
    }
    return false;
}

int evaluate(char board[3][3]){
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

int minimax(char board[3][3], bool depth, bool maximizingPlayer){
    int evaluateScore = evaluate(board);
    if(evaluateScore == 10 || evaluateScore == -10){
        return evaluateScore;
    }

    if(!movesLeft(board)){
        return 0;
    }
    
    if(maximizingPlayer){
        int value = std::numeric_limits<int>::max() * -1;

        for(int row = 0; row < 3; row++){
            for(int column = 0; column < 3; column++){
                //checking for all possibilities
                if(board[row][column] == '-'){
                    board[row][column] = aiO;
                    value = std::max(value, minimax(board, depth + 1, !maximizingPlayer));
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
                    board[row][column] = playerX;
                    value = std::min(value, minimax(board, depth + 1, !maximizingPlayer));
                    board[row][column] = '-';
                }
            }
        }
        return value;
    }
}

void movesBest(char board[3][3], std::pair<int, int> aiOptimal){
    int value = std::numeric_limits<int>::max() * - 1;

    aiOptimal = std::make_pair(-1, -1);
    
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(board[row][column] == '-'){
                board[row][column] = aiO;
                int tempValue = minimax(board, 0, false);
                board[row][column] = '-';

                if(value < tempValue){   
                    aiOptimal.first = row;
                    aiOptimal.second = column;
                    value = tempValue; 
                }   
            }
        }
    }
    
    std::cout << "BEST VALUE " << value << std::endl;
    std::cout << "Row:" << aiOptimal.first + 1 << " Column:" << aiOptimal.second + 1 << std::endl;
    
    movesMake(board, aiOptimal.first, aiOptimal.second, 1);
}

void gameState(char board[3][3]){
    int value = evaluate(board);

    if((!movesLeft(board) && value == 0) || value == -10 || value == 10){
        if(!movesLeft(board) && value == 0){
            std::cout << "Tie!" << std::endl;
        }
        else if(value == -10){
            std::cout << "Player Wins!" << std::endl;
        }
        else if(value == +10){
            std::cout << "Ai Wins!" << std::endl;
        }
        std::cout << "Game Reset" << std::endl << std::endl;
        resetBoard(board);
        drawBoard(board);
    }

    
}

int main(){
    
    srand (time(NULL));
    int playerOrAi = rand() % 2;

    char board[3][3] = { {'-', '-', '-'},
                         {'-', '-', '-'},
                         {'-', '-', '-'} };
    
    std::cout << "Game Start" << std::endl;                                                            
    drawBoard(board);
    std::cout << std::endl;
    
    while(true){
        
        gameState(board);

        if(playerOrAi == 0){
            std::cout << "Player's Turn" << std::endl;

            std::cout << "Row: ";
            int row;
            std::cin >> row;

            std::cout << "Column: ";
            int column;
            std::cin >> column;

            movesMake(board, row - 1, column - 1, 0);
            drawBoard(board);
            std::cout << std::endl;

            playerOrAi = 1;

        }
        else if(playerOrAi == 1){
            std::cout << "Ai's Turn" << std::endl;

            std::pair<int, int> aiOptimal; 
            movesBest(board, aiOptimal);  
            
            drawBoard(board);
            std::cout << std::endl;

            playerOrAi = 0;
        }
    }  
}   