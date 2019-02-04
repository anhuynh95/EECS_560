#ifndef NODE_H
#define NODE_H
class Node
{
public:
	Node();
  Node(int num);
  int getNum() const;
  void setNum(int num);
  Node* getNext() const;
  void setNext(Node* nextNode);

private:
  int m_number;
  Node* next;
};
#endif
