pro: main.o
	g++ -std=c++11 main.o Node.o MaxLeftist.o -o pro

main.o:	main.cpp MaxLeftist.o Node.o
	g++ -std=c++11 -c main.cpp

MaxLeftist.o: MaxLeftist.cpp MaxLeftist.h
	g++ -std=c++11 -c MaxLeftist.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -c Node.cpp

test: pro main.cpp
	./pro

clean:
	rm *o output
