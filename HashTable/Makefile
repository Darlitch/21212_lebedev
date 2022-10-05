Flags := -Wall -Wextra -Werror

HashTable: HashTable.o TValue.o main.o
	g++ HashTable.o TValue.o main.o -o HashTable

HashTable.o: HashTable.cpp
	g++ $(Flags) -c HashTable.cpp

TValue.o: TValue.cpp
	g++ $(Flags) -c TValue.cpp

main.o: main.cpp
	g++ $(Flags) -c main.cpp

Clean:
	rm -rf *.o