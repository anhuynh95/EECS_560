pro: main.o
	g++ -g -std=c++11 -Wall main.o -o pro

main.o: main.cpp Optimal.h Optimal.cpp BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o pro
