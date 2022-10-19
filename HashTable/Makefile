Flags := -Wall -Wextra -Werror
GCFlags := -fprofile-arcs -ftest-coverage

HashTable: HashTable.o TValue.o main.o
	g++ $(GCFlags) HashTable.o TValue.o main.o -o HashTable -lgtest -lgtest_main -lpthread
	rm -rf *.o

HashTable.o: HashTable.cpp
	g++ $(GCFlags) $(Flags) -c HashTable.cpp

TValue.o: TValue.cpp
	g++ $(GCFlags) $(Flags) -c TValue.cpp

main.o: main.cpp
	g++ $(GCFlags) $(Flags) -c main.cpp

lcov:
	lcov -t "HashTable" -o HashTable.info -c -d .
	genhtml -o report HashTable.info

Clean:
	rm -rf report
	rm -rf *.gc*
	rm -rf *.info
	rm -rf HashTable