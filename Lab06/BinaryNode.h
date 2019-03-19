#ifndef BINARY_NODE_H
#define BINARY_NODE_H
#include <string>
using namespace std;

class BinaryNode
{
public:
  BinaryNode();
  void setValue(int val);
  void setWord(std::string w);
  void setLeft(BinaryNode* left);
  void setRight(BinaryNode* right);
  int getValue();
  std::string getWord();
  BinaryNode* getLeft();
  BinaryNode* getRight();
private:
  BinaryNode* m_left;
  BinaryNode* m_right;
  int m_value;
  std::string m_word;
};

#endif
