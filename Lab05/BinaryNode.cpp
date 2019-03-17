#include "BinaryNode.h"

BinaryNode::BinaryNode(){
	m_left = nullptr;
	m_right = nullptr;
	m_value = 0;
}

void BinaryNode::setValue(int val) {
    m_value = val;
}

int BinaryNode:: getValue() {
  return m_value;
}

void BinaryNode::setLeft(BinaryNode* left) {
  m_left = left;
}

BinaryNode* BinaryNode::getLeft() {
  return m_left;
}

void BinaryNode::setRight(BinaryNode* right) {
  m_right = right;
}

	BinaryNode* BinaryNode::getRight() {
    return m_right;
  }
