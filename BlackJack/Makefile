FLAGS := -Werror -Wextra -Wall

all: Game.o BlackJack.o Strategy.o
	g++ -g Game.o -g BlackJack.o Strategy.o -o BlackJack

Game.o: Game.cpp
	g++ $(FLAGS) -c -O0 Game.cpp

BlackJack.o: BlackJack.cpp
	g++ $(FLAGS) -c -O0 BlackJack.cpp

Strategy.o: Strategy.cpp
	g++ $(FLAGS) -c -O0 Strategy.cpp

clean:
	-rm -rf *.o