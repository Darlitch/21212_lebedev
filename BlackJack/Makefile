FLAGS := -Werror -Wextra -Wall

all: Game.o BlackJack.o
	g++ Game.o BlackJack.o -o BlackJack

Game.o: Game.cpp
	g++ $(FLAGS) -c Game.cpp

BlackJack.o: BlackJack.cpp
	g++ $(FLAGS) -c BlackJack.cpp

clean:
	-rm -rf *.o