#ifndef MAXFIVEHEAP_H
#define MAXFIVEHEAP_H
#include <iostream>

class MaxFiveHeap {
public:
  MaxFiveHeap(int* arr, int s);
  ~MaxFiveHeap();
  void buildheap();
  void insert(int x);
  void deletemin();
  void findmin();
  void deletemax();
  void findmax();
  void levelorder();

private:
  int findLastParent();
  int findLargestNodeinNextLevel(int index);
  void printChild(int index);
  int* maxHeap;
  int size;
};
#endif
