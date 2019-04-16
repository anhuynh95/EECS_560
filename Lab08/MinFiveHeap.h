#ifndef MINFIVEHEAP_H
#define MINFIVEHEAP_H
#include <iostream>

class MinFiveHeap {
public:
  MinFiveHeap(int* arr, int s);
  ~MinFiveHeap();
  void buildheap();
  void insert(int x);
  void deletemin();
  void findmin();
  void deletemax();
  void findmax();
  void levelorder();

private:
  int findLastParent();
  int findSmallestNodeinNextLevel(int index);
  void printChild(int index);
  int* minHeap;
  int size;
};
#endif
