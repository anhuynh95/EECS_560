#ifndef NODE_H
#define NODE_H
using namespace std;

class Node
{
  public:
    Node(int x);
    int getRank() const;
    void setRank(int x);
    int getKey() const;
    void setKey(int x);
    Node * getLeft() const;
    void setLeft(Node* x);
    Node* getRight() const;
    void setRight(Node * x);

  private:
    int key;
    int rank;
    Node * left;
    Node * right;

};
#endif
