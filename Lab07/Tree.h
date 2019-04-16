#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree
{
  public:
    Tree();
    ~Tree();
    bool IsEmpty();
    void Insert(char input);
    void Delete(char input);
    char  FindData(char input);
    void DeleteMin();
    void DeleteMax();
    char FindMin();
    char FindMax();
    void LevelOrder();
  private:

    struct myQueue{
      Node* item;
      myQueue* next;
    };
    Node *root;
    Node *travelPos;
    void destroy(Node *travelPos);
    char myFind(Node* travelPos, char input);
    char myFindMax(Node *travelPos);
    void updateParent(Node* parent, Node* leaf);
    void updateParent2(Node *ancestorPtr);
    void setNewNode(Node* node, char minL, Node* pa, char minR, char val, bool ta, Node* le, Node* mi, Node* r);
    int height(Node* node);
    void printPostOrder(Node *root);
    void printGivenLevel(Node *root, int level );
};

#endif
