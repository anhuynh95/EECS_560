#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
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
  bool isHere(int x);
  void DeleteFront();
  int getFront() const;
private:
  void sort();
  Node* head;
  int length;
};
#endif
