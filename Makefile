CXX=g++
CFLAGS=-std=c++17
INC=-I./include
LDFLAGS=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

all: build/TicTacToe.exe

build/TicTacToe.exe: build/Main.o build/Game.o build/Board.o
	$(CXX) -o build/TicTacToe.exe build/Main.o build/Game.o build/Board.o $(LDFLAGS)

build/Main.o: src/Main.cpp include/TicTacToe/Game.hpp
	$(CXX) $(CFLAGS) -c src/Main.cpp -o build/Main.o $(INC)

build/Game.o: src/Game.cpp include/TicTacToe/Game.hpp
	$(CXX) $(CFLAGS) -c src/Game.cpp -o build/Game.o $(INC)

build/Board.o: src/Board.cpp include/TicTacToe/Board.hpp
	$(CXX) $(CFLAGS) -c src/Board.cpp -o build/Board.o $(INC)

run: all
	./build/TicTacToe.exe

clean:
	-rm build/*.o build/*.exe