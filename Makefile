game: game.cpp tik_tak_toe.o
	g++ game.cpp tik_tak_toe.o -o game

tik_tak_toe.o: tik_tak_toe.cpp tik_tak_toe.hpp
	g++ -c tik_tak_toe.cpp

clean:
	rm *.o game
