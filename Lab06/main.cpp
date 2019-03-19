#include "Optimal.h"
#include "Optimal.cpp"
#include "BinaryNode.h"
//#include "BinaryNode.cpp"
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include <iostream>
#include <fstream>
#include <string>
//using namespace std;

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
    std::string temp;
    int cnt = 0;
     while(inFile>>temp)
     {
       cnt++;
     }
     inFile.clear();
     inFile.seekg(0, ios::beg);
     Optimal op(cnt);
     while(inFile>>temp)
     {
       op.Insert(temp);
     }
     inFile.close();
     op.Run();
     cout<<"Here is the optimal BST:\n";
     op.buildTree(1, op.getMySize());
     op.Printsam();
     cout<<endl<<endl;
     cout<<"The minimal cost is: "<<std::fixed<< std::setprecision(3) <<op.getCost()<<endl;
  }
  return 0;
}
