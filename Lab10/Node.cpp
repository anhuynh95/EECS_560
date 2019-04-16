#include "Node.h"

Node::Node(int x)  {
  left = nullptr;
  right = nullptr;
  key = x;
  rank = 0;
}

int Node::getRank() const{
  return rank;
}

void Node::setRank(int x) {
  rank = x;
}

int Node::getKey() const{
  return key;
}

void Node::setKey(int x) {
  key = x;
}

Node* Node::getLeft() const   {
  return left;
}

void Node::setLeft(Node * x)  {
  left = x;
}

Node* Node::getRight() const  {
  return right;
}

void Node::setRight(Node* x)  {
  right  = x;
}
