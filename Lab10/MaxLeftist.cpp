#include "MaxLeftist.h"
#include <iostream>
using namespace std;

MaxLeftist::MaxLeftist()  {
  root = nullptr;
  size = 0;
}

void MaxLeftist::destroy(Node* x) {
  if(root != nullptr) {
		if(root->getLeft() != nullptr) {
			destroy(root->getLeft());
		}
		if(root->getRight() != nullptr) {
			destroy(root->getRight());
		}
		delete root;
	}
}

MaxLeftist::~MaxLeftist() {
  destroy(root);
}

bool MaxLeftist::IsEmpty() const{
  if(root == nullptr) return true;
  else return false;
}

Node* MaxLeftist::Merge(Node * h1, Node * h2)  {
  if(h1 == nullptr) return h2;
  else if(h2 == nullptr) return h1;
  else if(h1->getKey() < h2->getKey())  {//make sure h1 > h2 always
    Node * temp = h1;
    h1 = h2;
    h2 = temp;
  }
  h1->setRight(Merge(h1->getRight(), h2));
  Node* left = h1->getLeft();
  Node* right = h1->getRight();
  if((left == nullptr) && (right != nullptr)) {
    h1->setLeft(h2->getRight());
    h1->setRight(nullptr);
  }
  else{ //no need for other case because left > right always;
    if(left->getRank() < right->getRank())  {
      Node * temp = h1->getRight();
      h1->setRight(h1->getLeft());
      h1->setLeft(temp);
    }
    h1->setRank(h1->getRight()->getRank()+1);
  }
  return h1;
}

void MaxLeftist::Insert(int x)  {
  Node * temp = new Node(x);
  root = Merge(temp, root);
}

void MaxLeftist::myLevelorder (Node* tree, int level) {
  if(tree == nullptr) return;
	else if(level == 1) cout<<tree->getKey()<<" ";
	else if(level > 1)	{
		myLevelorder(tree->getLeft(), level - 1);
		myLevelorder(tree->getRight(), level - 1);
	}
}

int MaxLeftist::height(Node* tree)  {
  if(tree == nullptr) return 0;
	else	{
		int left = height(tree->getLeft());
		int right =  height(tree->getRight());
    if(left > right) return left+1;
    else return right+1;

	}
}

void MaxLeftist::Levelorder()	{
	int temp = height(root);
	for(int i =1; i<=temp; i++)
	{
		myLevelorder(root, i);
	}
	cout<<endl;
}
