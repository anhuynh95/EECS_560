pro: main.o
	g++ -g -std=c++11 -Wall main.o -o pro

main.o: main.cpp QuadHash.h QuadHash.cpp DoubHash.h DoubHash.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o pro