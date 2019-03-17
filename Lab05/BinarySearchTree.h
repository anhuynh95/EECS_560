#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE
#include <iostream>
#include "BinaryNode.h"
#include "BinaryNode.cpp"

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool IsEmpty() const;
		bool Insert(int val);
		void Inorder();
		void Postorder();
		void Preorder();
		void Levelorder();
		bool Delete(int val);
		bool Find(int val);
		int FindMin();
		int FindMax();

private:
		BinaryNode* m_root;
	  void deleteTree(BinaryNode* tree);
		bool myInsert(int val, BinaryNode* tree);
		void myInorder(BinaryNode* tree);
		void myPostorder(BinaryNode* tree);
		void myPreorder(BinaryNode* tree);
		void myLevelorder(BinaryNode* tree, int level);
		int height(BinaryNode* tree);
		bool isOn(int val);
		BinaryNode* findParent(BinaryNode* tree, BinaryNode* child);
		BinaryNode* myFind(BinaryNode* tree, int val);
};
#endif
