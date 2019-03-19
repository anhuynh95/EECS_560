#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
	m_root = nullptr;
}

void BinarySearchTree::deleteAll()	{
	deleteTree(m_root);
}

void BinarySearchTree::deleteTree(BinaryNode* tree) {
	if(tree != nullptr) {
		if(tree->getLeft() != nullptr) {
			deleteTree(tree->getLeft());
		}
		if(tree->getRight() != nullptr) {
			deleteTree(tree->getRight());
		}
		delete tree;
	}
}

BinarySearchTree::~BinarySearchTree() {
	deleteTree(m_root);
}

bool BinarySearchTree::IsEmpty() const {
	if (m_root == nullptr) return true;
	else return false;
}

bool BinarySearchTree::myInsert(int val, std::string word, BinaryNode* tree) {
	if(IsEmpty() == true)
	{
		BinaryNode* temp = new BinaryNode();
		temp -> setValue(val);
		temp -> setWord(word);
		m_root = temp;
		return true;
	}
	else if(val < tree->getValue())
	{
		if(tree->getLeft() == nullptr)
		{
			BinaryNode* temp = new BinaryNode();
			temp->setValue(val);
			temp->setWord(word);
			tree->setLeft(temp);
			return true;
		}
		else
		{
			return (myInsert(val, word, tree->getLeft()));
		}
	}
	else if (val >= tree->getValue())
	{
		if(tree->getRight() == nullptr)
		{
			BinaryNode* temp = new BinaryNode();
			temp->setValue(val);
			temp->setWord(word);
			tree->setRight(temp);
			return true;
		}
		else
		{
			return(myInsert(val, word, tree->getRight()));
		}
	}
	else return false;
}

int BinarySearchTree::height(BinaryNode* tree)	{
	if(tree == nullptr) return 0;
	else	{
		int left = height(tree->getLeft());
		int right =  height(tree->getRight());
		return max(left, right)+1;
	}
}

bool BinarySearchTree::Insert(int val, std::string w) {
	if(myInsert(val, w, m_root) == true)
	{
		//cout << "Insert was successful.\n";
		return true;
	}
	else	{
	//	cout << "Insert was failed.\n";
		return false;
	}
}

BinaryNode* BinarySearchTree::myFind(BinaryNode* tree, int val)	{
	  if (tree==nullptr)
		{
			return nullptr;
		}
	  else if(tree->getValue()==val)
		{
			BinaryNode* temp = new BinaryNode();
			temp = tree;
			return temp;
		}
	  else if(tree->getValue()>val)
	  {
			return (myFind(tree->getLeft(), val));
	  }
	  else if(tree->getValue()<=val)
	  {
	    return (myFind(tree->getRight(), val));
	  }
		else return nullptr;
}

BinaryNode* BinarySearchTree::findParent(BinaryNode* tree, BinaryNode* child)	{
	if (tree==nullptr)
	{
		return nullptr;
	}
	else if((tree->getLeft()==child)||(tree->getRight()==child)) return tree;
	else if(tree->getValue() > child->getValue()) return(findParent(tree->getLeft(), child));
	else if(tree->getValue() <= child->getValue()) return(findParent(tree->getRight(), child));
	else return nullptr;
}

bool BinarySearchTree::isOn(int val)	{
	if(Find(val)) return true;
	else return false;
}

bool BinarySearchTree::Delete(int val)	{
	if(m_root==nullptr) return (false);
	else if (m_root->getValue()==val)
	{
		BinaryNode* temp = m_root;
		if((temp->getLeft()==nullptr)&&(temp->getRight()==nullptr))
		{
			delete temp;
			m_root = nullptr;
		}
		else if(temp->getRight()==nullptr)
		{
			m_root = temp->getLeft();
			delete temp;
		}
		else if(temp->getLeft()==nullptr)
		{
			m_root=temp->getRight();
			delete temp;
		}
		else
    {
      BinaryNode* a = temp->getRight();
      BinaryNode* b = temp;
      while(a->getLeft()!=nullptr)
      {
        b = a;
        a=a->getLeft();
      }
      int tempVal = a->getValue();
      if(b!=temp) b->setLeft(a->getRight());
      else b->setRight(a->getRight());
      delete a;
      temp->setValue(tempVal);
    }
		cout<<"Delete was successful.\n";
    return true;
  }
	else if(!isOn(val))
	{
		cout<<"Delete was failed.\n";
		return false;
	}
  else
  {
    BinaryNode* temp = myFind(m_root, val);
    BinaryNode* parent = findParent(m_root, temp);
    bool left = parent->getLeft()==temp;
    if(temp->getLeft()==nullptr && temp->getRight()==nullptr)
    {
      if(left) parent->setLeft(nullptr);
      else parent->setRight(nullptr);
      delete temp;
    }
    else if(temp->getRight()==nullptr)
    {
      if(left) parent->setLeft(temp->getLeft());
      else parent->setRight(temp->getLeft());
      delete temp;
    }
    else if(temp->getLeft()==nullptr)
    {
      if(left) parent->setLeft(temp->getRight());
      else parent->setRight(temp->getRight());
      delete temp;
    }
    else
    {
      BinaryNode* a = temp->getRight();
      BinaryNode* b = temp;
      while(a->getLeft()!=nullptr)
      {
        b=a;
        a=a->getLeft();
      }
      int tempVal = a->getValue();
      if(b!=temp) b->setLeft(a->getRight());
      else b->setRight(a->getRight());
      delete a;
      temp->setValue(tempVal);
    }
    return true;
		cout<<"Delete was successful.\n";
  }


}

bool BinarySearchTree::Find(int val)	{
	if(myFind(m_root, val) == nullptr)
	{
		cout<<"Number is not present in tree. \n";
		return false;
	}
	else{
		cout<<"Number is present in tree. \n";
		return true;
	}
}


void BinarySearchTree::myInorder (BinaryNode* tree) {
	if(tree == nullptr) return;
	else {
		myInorder(tree->getLeft());
		cout<<tree->getValue()<<" ";
		myInorder(tree->getRight());
	}
}

void BinarySearchTree::Inorder()	{
	myInorder(m_root);
	cout<<endl;
}

void BinarySearchTree::myPostorder(BinaryNode* tree) {
	if(tree == nullptr) return;
	else {
		myPostorder(tree->getLeft());
		myPostorder(tree->getRight());
		cout<<tree->getValue()<<" ";
	}
}

void BinarySearchTree::Postorder()	{
	myPostorder(m_root);
	cout<<endl;
}

void BinarySearchTree::myPreorder(BinaryNode* tree) {
	if(tree == nullptr) return;
	else {
		cout<<tree->getValue()<<" ";
		myPreorder(tree->getLeft());
		myPreorder(tree->getRight());
	}
}

void BinarySearchTree::Preorder()	{
	myPreorder(m_root);
	cout<<endl;
}

void BinarySearchTree::myLevelorder (BinaryNode* tree, int level) {
	if(tree == nullptr) return;
	else if(level == 1) cout<<tree->getWord();
	else if(level > 1)	{
		myLevelorder(tree->getLeft(), level - 1);
		myLevelorder(tree->getRight(), level - 1);
	}
}

void BinarySearchTree::Levelorder()	{
	int temp = height(m_root);
	for(int i =1; i<=temp; i++)
	{
		myLevelorder(m_root, i);
	}
	cout<<endl;
}

void BinarySearchTree::myPrintTree(BinaryNode* tree, int space)	{
    if(tree == nullptr) return;
		else	{
			if(tree->getRight() != nullptr)	myPrintTree(tree->getRight(), space+4);
			if(space)	cout<<std::setw(space)<<" ";
			if(tree->getRight() != nullptr)	cout<<"  /\n" <<std::setw(space)<< " ";
			cout<<tree->getWord()<<endl;
			if(tree->getLeft() != nullptr)	cout<<std::setw(space) <<" "<<" \\\n";
			myPrintTree(tree->getLeft(), space+4);
		}
}

void BinarySearchTree::printTree()
{
    myPrintTree(m_root, 0);
}
