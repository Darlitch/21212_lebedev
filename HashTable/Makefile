Flags := -Wall -Wextra -Werror

HashTable: HashTable.o TValue.o
	g++ HashTable.o TValue.o -o HashTable

HashTable.o: HashTable.cpp
	g++ $(Flags) HashTable.cpp

TValue.o: TValue.cpp
	g++ $(Flags) TValue.cpp

Clean:
	rm -rf *.o