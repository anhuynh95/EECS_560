#include <iostream>
#include <fstream>
#include "Tree.h"
using namespace std;

Tree::Tree()  {
  root = nullptr;
  char input;
  ifstream inFile("data.txt");
  while(inFile >> input)
    Insert(input);
  inFile.close();
}

Tree::~Tree(){
  destroy(root);
}

void Tree::destroy(Node *travelPos){
    if(travelPos==nullptr)
        return;
    destroy(travelPos->getLeft());
    destroy(travelPos->getMid());
    destroy(travelPos->getRight());
    delete travelPos;
}

bool Tree::IsEmpty()  {
  if(root == nullptr) return true;
  else return false;
}

void Tree::setNewNode(Node* node, char minL, Node* pa, char minR, char val, bool ta, Node* le, Node* mi, Node* r) {
  node->setMinLeft(minL);
  node->setParent(pa);
  node->setMinRight(minR);
  node->setValue(val);
  node->setCheck(ta);
  node->setLeft(le);
  node->setMid(mi);
  node->setRight(r);
}

void Tree::Insert(char input) {
  if(IsEmpty()) {
    Node *temp = new Node;
    setNewNode(temp, 0, nullptr, 0, input, true, nullptr, nullptr, nullptr);
    root = temp;
  }
  else if(root->getCheck() == true)  {
    Node *temp = new Node;
    setNewNode(temp, 0, nullptr, 0, 0, false, nullptr, nullptr, nullptr);

    Node *temp2 = new Node;
    setNewNode(temp2, 0, nullptr, 0, input, true, nullptr, nullptr, nullptr);

    if(root->getValue() > temp2->getValue()){
        temp->setMinLeft(root->getValue());
        temp->setLeft(temp2);
        temp->setMid(root);
    }
    else{
        temp->setMinLeft(temp2->getValue());
        temp->setLeft(root);
        temp->setMid(temp2);
    }

    temp2->setParent(temp);
    root->setParent(temp);
    root = temp;
}
  else  {
    travelPos = root;
    while(travelPos->getCheck() != true){
      if(input < travelPos->getMinLeft())
        travelPos = travelPos->getLeft();
      else if((input >= travelPos->getMinLeft() && input < travelPos->getMinRight()) || travelPos->getMinRight() == 0)
        travelPos = travelPos->getMid();
      else
        travelPos = travelPos->getRight();
    }
    travelPos = travelPos->getParent();
    Node *temp = new Node;
    setNewNode(temp, 0, nullptr, 0, input, true, nullptr, nullptr, nullptr);
    if(travelPos->getMinRight() == 0){
       if(travelPos->getMinLeft() < temp->getValue()){
            travelPos->setMinRight(temp->getValue());
            travelPos->setRight(temp);
       }
        else{
           travelPos->setMinRight(travelPos->getMinLeft());
           travelPos->setRight(travelPos->getMid());
           Node* childPtr = travelPos->getLeft();

            if(childPtr->getValue() < temp->getValue()){
                travelPos->setMinLeft(temp->getValue());
                travelPos->setMid(temp);
            }
            else{
                travelPos->setMinLeft(childPtr->getValue());
                travelPos->setMid(travelPos->getLeft());
                travelPos->setLeft(temp);
            }
        }

      temp->setParent(travelPos);
    }
    else{
      Node *temp2 = new Node;
      setNewNode(temp2, 0, nullptr, 0, 0, false, nullptr, nullptr, nullptr);

      Node *temp2Root = new Node;
      setNewNode(temp2Root, 0, nullptr, 0, 0, false, nullptr, nullptr, nullptr);
      Node* parent = travelPos->getParent();


      if(temp->getValue() < travelPos->getMinLeft()){
        Node *childPtr = travelPos->getLeft();

        if(temp->getValue() > childPtr->getValue()){
          temp2->setMinLeft(temp->getValue());
          temp2->setLeft(travelPos->getLeft());
          temp2->setMid( temp);
        }
        else{
          temp2->setMinLeft( childPtr->getValue());
          temp2->setLeft(temp);
          temp2->setMid(travelPos->getLeft());
        }

        temp->setParent(temp2);
        childPtr->setParent(temp2);

        temp2Root->setMinLeft(travelPos->getMinLeft());
        temp2Root->setLeft(temp2);
        temp2Root->setMid(travelPos);
        travelPos->setMinLeft(travelPos->getMinRight());
        travelPos->setMinRight(0);
        travelPos->setLeft(travelPos->getMid());
        travelPos->setMid(travelPos->getRight());
        travelPos->setRight(nullptr);
        temp2->setParent(temp2Root);
        travelPos->setParent(temp2Root);
      }
      else if(temp->getValue() < travelPos->getMinRight()){
        temp2->setMinLeft(travelPos->getMinRight());
        temp2->setLeft(temp);
        temp2->setMid(travelPos->getRight());
        temp->setParent(temp2);
        Node* childPtr = travelPos->getRight();
        childPtr->setParent(temp2);
        temp2Root->setMinLeft( temp->getValue());
        temp2Root->setLeft(travelPos);
        temp2Root->setMid(temp2);
        travelPos->setMinRight(0);
        travelPos->setRight(nullptr);
        travelPos->setParent(temp2Root);
        temp2->setParent(temp2Root);
      }
      else {
        temp2->setMinLeft(temp->getValue());
        temp2->setLeft(travelPos->getRight());
        temp2->setMid(temp);
        temp->setParent(temp2);
        Node* childPtr = travelPos->getRight();
        childPtr->setParent(temp2);
        temp2Root->setMinLeft(travelPos->getMinRight());
        temp2Root->setLeft(travelPos);
        temp2Root->setMid(temp2);
        travelPos->setMinRight(0);
        travelPos->setRight(nullptr);
        travelPos->setParent(temp2Root);
        temp2->setParent(temp2Root);
      }
        updateParent(parent, temp2Root);
    }
  }
}

void Tree::updateParent(Node* parent, Node* leaf) {
  if(parent==nullptr){
      root = leaf;
      leaf->setParent(nullptr);
  }
  else if(parent->getMinRight() == 0){
    if(leaf->getMinLeft() < parent->getMinLeft()) {
      parent->setMinRight(parent->getMinLeft());
      parent->setMinLeft(leaf->getMinLeft());
      parent->setRight(parent->getMid());
      parent->setLeft(leaf->getLeft());
      parent->setMid(leaf->getMid());
    }
    else  {
      parent->setMinRight(leaf->getMinLeft());
      parent->setMid(leaf->getLeft());
      parent->setRight(leaf->getMid());
    }

    Node *fChild = leaf->getLeft();
    fChild->setParent(parent);
    Node *sChild = leaf->getMid();
    sChild->setParent(parent);
    delete leaf;
  }
  else  {
    Node *newNode = new Node;
    setNewNode(newNode, 0, nullptr, 0, 0, false, nullptr, nullptr, nullptr);
    Node *newRoot = new Node;
    setNewNode(newRoot, 0, nullptr, 0, 0, false, nullptr, nullptr, nullptr);
    Node* parentNew = parent->getParent();
    if(leaf->getMinLeft() < parent->getMinLeft()){
      newRoot->setMinLeft(parent->getMinLeft());
      newRoot->setLeft(leaf);
      newRoot->setMid(parent);
      parent->setMinLeft(parent->getMinRight());
      parent->setMinRight(0);
      parent->setLeft(parent->getMid());
      parent->setMid(parent->getRight());
      parent->setRight( nullptr);
      parent->setParent(newRoot);
      leaf->setParent(newRoot);
		  delete newNode;
    }
    else if(leaf->getMinLeft() < parent->getMinRight()){
      newNode->setMinLeft(parent->getMinRight());
      newNode->setLeft(leaf->getMid());
      newNode->setMid(parent->getRight());
      Node* childPtr = parent->getRight();
      childPtr->setParent(newNode);
      childPtr = leaf->getMid();
      childPtr->setParent(newNode);
      newRoot->setMinLeft(leaf->getMinLeft());
      newRoot->setLeft(parent);
      newRoot->setMid(newNode);
      parent->setMinRight(0);
      parent->setRight(nullptr);
      parent->setMid(leaf->getLeft());
      childPtr = leaf->getLeft();
      childPtr->setParent(parent);
      parent->setParent(leaf);
      newNode->setParent(leaf);
      delete leaf;
    }
    else {
      newRoot->setMinLeft(parent->getMinRight());
      newRoot->setLeft(parent);
      newRoot->setMid(leaf);
      parent->setMinRight(0);
      parent->setRight(nullptr);
      parent->setParent(newRoot);
      leaf->setParent(newRoot);
		  delete newNode;
    }
    updateParent(parentNew, newRoot);
  }
}

char Tree::FindData(char input) {
  if(IsEmpty()){
      cout << "The Tree is empty" << endl;
      return 0;
  }
  else{
      return myFind(root, input);			//recusrive call to traverse the tree to find the desired  node
  }
}

char Tree::myFind(Node* travelPos, char input){
   if(travelPos == nullptr)
    return 0;
   else{
    if(travelPos->getCheck() == true && travelPos->getValue() == input)
      return '-';
    else if(input < travelPos->getMinLeft())
      return myFind(travelPos->getLeft(), input);
    else if((input >= travelPos->getMinLeft() && input < travelPos->getMinRight())|| travelPos->getMinRight() == 0)
      return myFind(travelPos->getMid(), input);
    else
      return myFind(travelPos->getRight(), input);
   }
}

void Tree::Delete(char input){
  if(root->getCheck() == true && root->getValue() == input){
      delete root;
      root = nullptr;
  }
  else{
   travelPos = root;
   while(travelPos->getCheck() != true){
    if(input < travelPos->getMinLeft())
      travelPos = travelPos->getLeft();
    else if((input >= travelPos->getMinLeft() && input < travelPos->getMinRight()) || travelPos->getMinRight() == 0)
      travelPos = travelPos->getMid();
    else
      travelPos = travelPos->getRight();
  }
  Node* thisParent = travelPos->getParent();
  Node* thisAncestor = thisParent->getParent();
  if(thisParent->getMinRight() != 0){
    if(input <= thisParent->getMinLeft()){
      if(input < thisParent->getMinLeft()){
        thisParent->setLeft(thisParent->getMid());
        thisParent->setMid(thisParent->getRight());
      }
      else if(input == thisParent->getMinLeft()){
        thisParent->setMid(thisParent->getRight());
      }
      thisParent->setMinLeft(thisParent->getMinRight());
      thisParent->setMinRight(0);
      thisParent->setRight(nullptr);
    }
    else{
      thisParent->setMinRight(0);
      thisParent->setRight(nullptr);
    }

    delete travelPos;
    updateParent2(thisAncestor);
  }
  else{
    if(thisAncestor != nullptr){
      Node *thisSibling;
      if(input < thisAncestor->getMinLeft())
        thisSibling  = thisAncestor->getMid();
      else if((input >= thisAncestor->getMinLeft() && input < thisAncestor->getMinRight()) || thisAncestor->getMinRight() == 0)
        thisSibling = thisAncestor->getLeft();
      else
        thisSibling = thisAncestor->getMid();
      if(thisSibling->getMinRight() != 0){
        if(thisParent->getMinLeft() == input){
          if(input > thisSibling->getMinRight()){
            Node *tempPtr = thisParent->getLeft();
            thisParent->setMinLeft(tempPtr->getValue());
            thisParent->setMid(thisParent->getLeft());
            thisParent->setLeft(thisSibling->getRight());
            tempPtr = thisSibling->getRight();
            tempPtr->setParent(thisParent);
            thisSibling->setMinRight(0);
            thisSibling->setRight(nullptr);
          }
          else{
            Node *tempPtr = thisSibling->getLeft();
            thisParent->setMinLeft(tempPtr->getValue());
            tempPtr->setParent(thisParent);
            thisParent->setMid(thisSibling->getLeft());
            thisSibling->setLeft(thisSibling->getMid());
            thisSibling->setMid(thisSibling->getRight());
            thisSibling->setMinLeft(thisSibling->getMinRight());
            thisSibling->setMinRight(0);
            thisSibling->setRight(nullptr);
          }
        }
        else{
          if(input > thisSibling->getMinRight()){
            thisParent->setLeft(thisSibling->getRight());
            Node *tempPtr = thisSibling->getRight();
            tempPtr->setParent(thisParent);
            thisSibling->setMinRight(0);
            thisSibling->setRight( nullptr);
          }
          else{
            Node *tempPtr = thisSibling->getLeft();
            thisParent->setMinLeft(tempPtr->getValue());
            tempPtr->setParent(thisParent);
            thisParent->setLeft( thisParent->getMid());
            thisParent->setMid(thisSibling->getLeft());
            thisSibling->setLeft(thisSibling->getMid());
            thisSibling->setMid(thisSibling->getRight());
            thisSibling->setMinRight(0);
            thisSibling->setRight(nullptr);
            }
        }
          delete travelPos;
          updateParent2(thisAncestor);
      }
      else{
        if(input < thisSibling->getMinLeft()){
          Node *tempPtr = thisSibling->getLeft();
          thisSibling->setMinRight(thisSibling->getMinLeft());
          thisSibling->setMinLeft(tempPtr->getValue());
          thisSibling->setRight(thisSibling->getMid());
          thisSibling->setMid(thisSibling->getLeft());
          if(thisParent->getMinLeft() == input){
            thisSibling->setLeft(thisParent->getLeft());
            tempPtr = thisParent->getLeft();
            tempPtr->setParent(thisSibling);
          }
          else{
            thisSibling->setLeft(thisParent->getMid());
            tempPtr = thisParent->getMid();
            tempPtr->setParent(thisSibling);
          }
      }
      else{
        Node *tempPtr;
        if(thisParent->getMinLeft() == input){
          thisSibling->setRight(thisParent->getLeft());
          tempPtr = thisParent->getLeft();
          tempPtr->setParent(thisSibling);
          thisSibling->setMinRight(tempPtr->getValue());
        }
        else{
          thisSibling->setRight(thisParent->getMid());
          tempPtr = thisParent->getMid();
          tempPtr->setParent(thisSibling);
          thisSibling->setMinRight(tempPtr->getValue());
        }
      }
      if(thisParent->getMinLeft() < thisAncestor->getMinLeft()){
        if(thisAncestor->getMinRight() != 0){
          thisAncestor->setLeft(thisAncestor->getMid());
          thisAncestor->setMid(thisAncestor->getRight());
          thisAncestor->setRight(nullptr);
        }
        else{
          thisAncestor->setLeft(thisAncestor->getMid());
          thisAncestor->setMid(nullptr);
        }
      }
      else if((thisParent->getMinLeft() >= thisAncestor->getMinLeft() && thisParent->getMinLeft() < thisAncestor->getMinRight()) || thisAncestor->getMinRight() == 0) {
        if(thisAncestor->getMinRight() != 0)  {
          thisAncestor->setMid(thisAncestor->getRight());
          thisAncestor->setRight(nullptr);
        }

          thisAncestor->setMid( nullptr);
        }
        else  {
          if(thisAncestor->getMinRight() != 0)
            thisAncestor->setRight(nullptr);
          }
          delete travelPos;
          delete thisParent;
          updateParent2(thisAncestor);
        }
        }

    else{
      if(input == thisParent->getMinLeft()){
        Node *tempPtr = thisParent->getLeft();
        tempPtr->setParent(nullptr);
          root  = tempPtr;
      }
      else{
        Node *tempPtr = thisParent->getMid();
        tempPtr->setParent(nullptr);
        root = tempPtr;
      }
      delete travelPos;
      delete thisParent;
    }
  }
}
}

void Tree::updateParent2(Node *thisParent){

if(thisParent != nullptr){
 if(thisParent->getMid() != nullptr){
    Node *travelPos = thisParent->getMid();
    while(travelPos->getCheck() != true)
        travelPos = travelPos->getLeft();

    if(travelPos->getValue() != thisParent->getMinLeft()){
        thisParent->setMinLeft(travelPos->getValue());

    }

    if(thisParent->getRight() != nullptr){
        travelPos = thisParent->getRight();
        while(travelPos->getCheck() != true)
            travelPos = travelPos->getLeft();

        if(travelPos->getValue() != thisParent->getMinRight()){
            thisParent->setMinRight(travelPos->getValue());
        }
    }
    else
        thisParent->setMinRight(0);
 }
 else{
        Node* thisAncestor = thisParent->getParent();

        if(thisAncestor != nullptr){
                Node *thisSibling;

            if(thisParent->getMinLeft() < thisAncestor->getMinLeft())
                thisSibling  = thisAncestor->getMid();
            else if((thisParent->getMinLeft() >= thisAncestor->getMinLeft() && thisParent->getMinLeft() < thisAncestor->getMinRight()) || thisAncestor->getMinRight() == 0)
                thisSibling = thisAncestor->getLeft();
            else
                thisSibling = thisAncestor->getMid();

            if(thisSibling->getMinRight()==0){
               if(thisParent->getMinLeft() < thisSibling->getMinLeft()){
                    thisSibling->setMinRight(thisSibling->getMinLeft());
                    Node *temp = thisSibling->getLeft();
                    while(temp->getCheck() != true)
                        temp = temp->getLeft();

                    thisSibling->setMinLeft(temp->getValue());
                    thisSibling->setRight(thisSibling->getMid());
                    thisSibling->setMid(thisSibling->getLeft());
                    thisSibling->setLeft(thisParent->getLeft());

                    temp = thisParent->getLeft();
                    temp->setParent(thisSibling);
               }
               else{
                    Node *temp = thisParent->getLeft();
                    while(temp->getCheck() != true)
                        temp = temp->getLeft();
                    thisSibling->setMinRight(temp->getValue());

		                temp = thisParent->getLeft();
		                temp->setParent(thisSibling);
                    thisSibling->setRight(thisParent->getLeft());
               }

               if(thisParent->getMinLeft() < thisAncestor->getMinLeft()){
                        if(thisAncestor->getMinRight() != 0){
                            thisAncestor->setLeft(thisAncestor->getMid());
                            thisAncestor->setMid(thisAncestor->getRight());
                            thisAncestor->setRight(nullptr);
                        }
                        else{
                            thisAncestor->setLeft(thisAncestor->getMid());
                            thisAncestor->setMid(nullptr);
                        }
               }
              else if((thisParent->getMinLeft() >= thisAncestor->getMinLeft() && thisParent->getMinLeft() < thisAncestor->getMinRight()) || thisAncestor->getMinRight() == 0){
                        if(thisAncestor->getMinRight() != 0){
                            thisAncestor->setMid(thisAncestor->getRight());
                            thisAncestor->setRight( nullptr);
                        }
                        else
                            thisAncestor->setMid(nullptr);
                }
              else{
                        if(thisAncestor->getMinRight() != 0)
                            thisAncestor->setRight(nullptr);
                        }

               delete thisParent;
               updateParent2(thisAncestor);
            }
            else{
                 if(thisParent->getMinLeft() < thisSibling->getMinLeft()){
                    Node *temp = thisSibling->getLeft();
                    thisParent->setMinLeft(temp->getValue());
                    temp->setParent(thisParent);
                    thisParent->setMid(thisSibling->getLeft());
                    thisParent->setRight(nullptr);
                    thisParent->setMinRight(0);

                    thisSibling->setMinLeft(thisSibling->getMinRight());
                    thisSibling->setMinRight(0);
                    thisSibling->setLeft(thisSibling->getMid());
                    thisSibling->setMid(thisSibling->getRight());
                    thisSibling->setRight( nullptr);
                }
                else{
                        Node *temp = thisParent->getLeft();
                        thisParent->setMinLeft(temp->getValue());
                        thisParent->setMinRight(0);
                        thisParent->setMid(thisParent->getLeft());
                        thisParent->setLeft(thisSibling->getRight());
                        thisParent->setRight(nullptr);

                        temp= thisSibling->getRight();
                        temp->setParent(thisParent);
                        thisSibling->setMinRight(0);
                        thisSibling->setRight(nullptr);
                }

              updateParent2(thisAncestor);
            }
        }
        else{
                Node *tempPtr = thisParent->getLeft();
                tempPtr->setParent(nullptr);
                root  = tempPtr;

               delete thisParent;
        }
    }
}
}

char Tree::FindMin()  {
  travelPos = root;

  if(travelPos == nullptr){
      return 0;
  }
  else{
      while(travelPos->getLeft() != nullptr){
          travelPos = travelPos->getLeft();
      }
      return travelPos->getValue();
  }
}

char Tree::FindMax(){
    return myFindMax(root);
}

char Tree::myFindMax(Node *travelPos) {
  if(travelPos == nullptr)
    return 0;
  else if(travelPos->getCheck() == true)
    return travelPos->getValue();
  else{
    if(travelPos->getRight() != nullptr)
        travelPos = travelPos->getRight();
    else
        travelPos = travelPos->getMid();
    return myFindMax(travelPos);
  }
}

void Tree::DeleteMax(){
    char temp = FindMax();
    if(temp == 0){
        cout << "The Tree is empty" << endl;
    }
    else{
        Delete(temp);
        cout << temp << endl;
    }
}

void Tree::DeleteMin(){
    char temp = FindMin();
    if(temp == 0)
        cout << "The Tree is empty" << endl;
    else{
        Delete(temp);
        cout << temp << endl;
    }
}


int Tree::height(Node* node)  {
  if( node == nullptr ){
		return 0;
	} else if( node->getCheck() == true ){
		return 1;
	} else {
		int lHeight = height(node->getLeft());
		int mHeight = height(node->getMid());
		int rHeight = height(node->getRight());

		if( lHeight > mHeight && lHeight > rHeight ){
			return lHeight+1;
		} else if( mHeight > rHeight){
			return mHeight+1;
		} else {
			return rHeight+1;
		}
	}
}

void Tree::printPostOrder(Node *root){
  if(root->getLeft() != nullptr) {
    cout<<"AAAAAAAAAAAA";
  }
  printPostOrder(root->getLeft());


}

void Tree::printGivenLevel(Node *root, int level ){
	if( root->getValue() == 0 ){
		return;
	}
  if( root == nullptr ){
		return;
	}
	if( level == 1 ){

			cout<<root->getValue()<<endl;

		cout << endl;
	} else if( level > 1 ){
		printGivenLevel( root->getLeft(), level-1 );
		printGivenLevel( root->getMid(), level-1 );
		printGivenLevel( root->getRight(), level-1 );
	}
  else cout<<"error";
}

void Tree::LevelOrder(){

if(root != nullptr){
 Node *travelPosleft, *travelPosmid, *travelPosright;
 myQueue* temp, *travList;
 myQueue *newNode = new myQueue;
 newNode->item = root;
 newNode->next = nullptr;
 temp = newNode;
 travList = newNode;
 while(travList!= nullptr){
   travelPos = travList->item;

if(travelPos->getParent() == nullptr && travelPos->getCheck() == true)
  cout << travelPos->getValue() << " ";

if(travelPos->getLeft() != nullptr){
  travelPosleft = travelPos->getLeft();
  myQueue *newNode = new myQueue;
  newNode->item = travelPos->getLeft();
  newNode->next = nullptr;
  temp->next = newNode;
  temp = newNode;
  if(travelPosleft != nullptr && travelPosleft->getCheck() == true)
    cout << travelPosleft->getValue() << " ";
}

if(travelPos->getMid() != nullptr){
  travelPosmid = travelPos->getMid();
  myQueue *newNode = new myQueue;
  newNode->item = travelPos->getMid();
  newNode->next = nullptr;
  temp->next = newNode;
  temp = newNode;

  if(travelPosmid != nullptr && travelPosmid->getCheck() == true)
    cout << travelPosmid->getValue() << " ";
  }

   if(travelPos->getRight() != nullptr){
    travelPosright = travelPos->getRight();
    myQueue *newNode = new myQueue;
    newNode->item = travelPos->getRight();
    newNode->next = nullptr;
    temp->next = newNode;
    temp = newNode;
    if(travelPosright != nullptr && travelPosright->getCheck() == true)
      cout << travelPosright->getValue() << " ";
   }
    myQueue *destruct = travList;
    travList = travList->next;
    delete destruct;
  }
}
else
    cout << "The tree is empty" << endl;


//cout<<height(root)<<endl;


//printGivenLevel(root, 3);
//printPostOrder(root);
}
