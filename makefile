CXX = g++
FLAGS = -Wall
LINKS = -lcurses

all: clean game

game:	main.cpp
	$(CXX) $(FLAGS) main.cpp actionbuffer.h player_char.h -o game $(LINKS)

clean:
	rm game
	rm -rf *.o
