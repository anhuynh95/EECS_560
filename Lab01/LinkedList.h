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
  //void Merge2Lists(Node<int>* m_front);
  void Print();
private:
  void sort();
  Node* head;
  int length;
};
#include "LinkedList.cpp"
#endif
