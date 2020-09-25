CXX=g++
CFLAGS=-std=c++17

all: build/TicTacToe.exe

build/TicTacToe.exe: build/Main.o
	$(CXX) build/Main.o -o build/TicTacToe.exe -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

build/Main.o: src/Main.cpp
	$(CXX) $(CFLAGS) -c src/Main.cpp -o build/Main.o

run: all
	./build/TicTacToe.exe

clean:
	-rm build/*.o build/*.exe