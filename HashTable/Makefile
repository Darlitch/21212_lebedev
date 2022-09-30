Flags := -Wall -Wextra -Werror

HashTable: HashTable.o
	g++ HashTable.o -o HashTable

HashTable.o: HashTable.cpp
	g++ $(Flags) HashTable.cpp

Clean:
	rm -rf *.o