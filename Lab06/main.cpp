#include "Optimal.h"
#include "Optimal.cpp"
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
     cout<<"Here is the optimal BST (in PreOrder):\n";
     op.Print(0);
     cout<<endl<<endl;
     cout<<"The minimal cost is: "<<op.getCost()<<endl<<endl;
  }
  return 0;
}
