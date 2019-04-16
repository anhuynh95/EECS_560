#include "MaxLeftist.h"
#include "Node.h"
//#include "MinMax.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void print()  {
  cout<<"\nPlease choose one of the following commands:\n1- Insert\n2- DeleteMax\n3- FindMax\n4- Preorder\n5- Inorder\n6- Levelorder\n7- Exit\nYour Choice: ";
}

int main()  {
  ifstream inFile;
  inFile.open("data.txt");
  if(!inFile)
  	{
	   cout<<"Unable to open data.txt or the file is not in the same folder. \n";
	}
  else
  {
    // int choice = 0;
    //
    // // while(inFile >> a)  {
    // //
    // // }
    // inFile.close();
    //
    // while(true) {
    //   print();
    //   cin>>choice;
    //   while(std::cin.fail())
    // {
    //   std::cin.clear();
    //   std::cin.ignore();
    //   cout<<"Input a number not a leter\n";
    //   std::cin >> choice;
    // }
    //
    // }
    MaxLeftist maxHeap;
    maxHeap.Insert(1);
   maxHeap.Insert(3);
     maxHeap.Insert(2);
     maxHeap.Insert(4);

    maxHeap.Levelorder();






  }

  return 0;
}
