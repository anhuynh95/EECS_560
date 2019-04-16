#ifndef NODE_H
#define NODE_H
using namespace std;

class Node
{
  public:
    Node();
    Node* getParent();
    void setParent(Node* node);
    Node* getLeft();
    void setLeft(Node* node);
    Node* getMid();
    void setMid(Node* node);
    Node* getRight();
    void setRight(Node* node);
    char getMinLeft();
    void setMinLeft(char node);
    char getMinRight();
    void setMinRight(char node);
    char getValue();
    void setValue(char node);
    bool getCheck();
    void setCheck(bool node);
  private:
    Node* parent;
    Node* left;
    Node* mid;
    Node* right;
    char minLeft;
    char minRight;
    char value;
    bool check;

};
#endif
