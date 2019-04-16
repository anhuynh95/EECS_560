#include "Node.h"
Node::Node()  {
  parent = nullptr;
  left = nullptr;
  mid  = nullptr;
  right = nullptr;
  minLeft = 0;
  char minRight = 0;
  char value = 0;
  check = false;
}


Node* Node::getParent() {
  return parent;
}

Node* Node::getLeft() {
  return left;
}

void Node::setParent(Node* node)  {
  parent = node;
}

void Node::setLeft(Node* node)  {
  left = node;
}

Node* Node::getMid() {
  return mid;
}

void Node::setMid(Node* node)  {
  mid = node;
}

Node* Node::getRight() {
  return right;
}

void Node::setRight(Node* node)  {
  right = node;
}

char Node::getMinLeft() {
  return minLeft;
}
void Node::setMinLeft(char node)  {
  minLeft = node;
}

char Node::getMinRight() {
  return minRight;
}
void Node::setMinRight(char node)  {
  minRight = node;
}

char Node::getValue() {
  return value;
}
void Node::setValue(char node)  {
  value = node;
}

bool Node::getCheck() {
  return check;
}
void Node::setCheck(bool node)  {
  check = node;
}
