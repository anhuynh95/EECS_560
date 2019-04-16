pro: main.o
	g++ -std=c++11 main.o Node.o Tree.o -o pro

main.o:	main.cpp Tree.o Node.o
	g++ -std=c++11 -c main.cpp

Tree.o: Tree.cpp Tree.h
	g++ -std=c++11 -c Tree.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -c Node.cpp

clean:
	rm *o output
