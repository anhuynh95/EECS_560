pro: main.o MinMax.o
	g++ -std=c++11 -g -Wall MinMax.o main.o -o pro

main.o: MinMax.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

MinMax.o: MinMax.h MinMax.cpp
	g++ -std=c++11 -g -Wall -c MinMax.cpp

test: pro main.cpp
	./pro

clean:
	rm *.o pro
