pro: main.o MinFiveHeap.o MaxFiveHeap.o
	g++ -std=c++11 -g -Wall MinFiveHeap.o MaxFiveHeap.o main.o -o pro

main.o: MinFiveHeap.h MaxFiveHeap.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

MinFiveHeap.o: MinFiveHeap.h MinFiveHeap.cpp
	g++ -std=c++11 -g -Wall -c MinFiveHeap.cpp

MaxFiveHeap.o: MaxFiveHeap.h MaxFiveHeap.cpp
	g++ -std=c++11 -g -Wall -c MaxFiveHeap.cpp


clean:
	rm *.o pro
