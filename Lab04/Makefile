pro: main.o
	g++ -g -std=c++11 -Wall main.o -o pro

main.o: main.cpp Node.h Node.cpp HashTable.h HashTable.cpp Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o pro
