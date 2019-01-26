#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <iostream>
class LinkedList
{
public:
  LinkedList();
  ~LinkedList();
  bool IsEmpty() const;
  void Insert(int num);
  void Delete(int num);
  int Smallest() const;
  int Largest() const;
  double Average() const;
  void Merge2Lists(LinkedList& newList);
  void Print();
private:
  void sort();
  void DeleteFront();
  int getFront() const;
  Node* head;
  int length;
};
#include "LinkedList.cpp"
#endif
