#ifndef MAXLEFTIST_H
#define MAXLEFTIST_H
#include "Node.h"
using namespace std;

class MaxLeftist {
public:
  MaxLeftist();
  ~MaxLeftist();

  void Buildheap();
  void Insert(int x);
  void Deletemax();
  void Findmax();
  Node* Merge(Node* h1, Node* h2);
  void Preorder();
  void Inorder();
  void Levelorder();
private:
  void destroy(Node * x);
  bool IsEmpty()  const;
  void myLevelorder (Node* tree, int level);
  int height(Node * tree);
  Node * root;
  int size;
};
#endif
