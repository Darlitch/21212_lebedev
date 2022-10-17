Flags := -Wall -Wextra -Werror

HashTable: HashTable.o TValue.o main.o
	g++ --coverage HashTable.o TValue.o main.o -o HashTable -lgtest -lgtest_main -lpthread
	rm -rf *.o

HashTable.o: HashTable.cpp
	g++ --coverage $(Flags) -c HashTable.cpp

TValue.o: TValue.cpp
	g++ --coverage $(Flags) -c TValue.cpp

main.o: main.cpp
	g++ --coverage $(Flags) -c main.cpp

lcov:
	lcov -t "HashTable" -o HashTable.info -c -d .
	genhtml -o report HashTable.info

Clean:
	rm -rf report
	rm -rf *.gc*
	rm -rf *.info
	rm -rf HashTable