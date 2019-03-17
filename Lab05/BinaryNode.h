#ifndef BINARY_NODE_H
#define BINARY_NODE_H
using namespace std;

class BinaryNode
{
public:
  BinaryNode();
  void setValue(int val);
  void setLeft(BinaryNode* left);
  void setRight(BinaryNode* right);
  int getValue();
  BinaryNode* getLeft();
  BinaryNode* getRight();
private:
  BinaryNode* m_left;
  BinaryNode* m_right;
  int m_value;
};

#endif
