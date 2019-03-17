#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream inFile;
  inFile.open("data.txt");
  if(!inFile)
  	{
	   cout<<"Unable to open data.txt or the file is not in the same folder. \n";
	}
  else
  {
    int temp;
    int choice;
    BinarySearchTree tree;
    while(inFile>>temp)
    {
       tree.Insert(temp);
    }
    while (true){
    cout<<"‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐\n Please choose one of the following commands: \n 1‐  Insert  \n 2‐  Delete  \n 3‐  Find \n 4‐  FindMin\n 5‐  FindMax \n 6‐  Preorder \n 7‐  Inorder \n 8‐  Postorder \n 9‐  Levelorder \n 10‐ Exit \n";
    cout<<"Your choice: ";
    cin>>choice;
    while(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
      std::cin >> choice;
    }

    if(choice == 1){
      int val;
      cout<<"Enter a number to be inserted: ";
      cin>>val;
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore();
        cout<<"ERROR: Input need to be an int.\n";
      }
      else tree.Insert(val);
    }
    else if(choice == 2)  {
      int val;
      cout<<"Enter a number to be deleted: ";
      cin>>val;
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore();
        cout<<"ERROR: Input need to be an int.\n";
      }
      else tree.Delete(val);
    }
    else if(choice == 3)  {
      int val;
      cout<<"Enter a number to be found: ";
      cin>>val;
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore();
        cout<<"ERROR: Input need to be an int.\n";
      }
      else tree.Find(val);
    }
    else if(choice == 4)  {
      cout<<"Minimum number: "<<tree.FindMin()<<endl;
    }
    else if(choice == 5)  {
      cout<<"Maximum number: "<<tree.FindMax()<<endl;
    }
    else if(choice == 6)  tree.Preorder();
    else if(choice == 7)  tree.Inorder();
    else if(choice == 8)  tree.Postorder();
    else if(choice == 9)  tree.Levelorder();
    else if(choice == 10) {
      cout<<"Done!\n";
      return false;
    }
    else cout<<"Your choice in not one of these options.\n";
  }






  }
  return 0;
}
