pro: main.o
	g++ -g -std=c++11 -Wall main.o -o pro

main.o: main.cpp LinkedList.h LinkedList.cpp Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o pro
