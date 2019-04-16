#include "MinMax.h"
//#include "MinMax.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void print()  {
  cout<<"\nPlease choose one of the following commands:\n1- Insert\n2- DeleteMin\n3- DeleteMax\n4- FindMin\n5- FindMax\n6- RunSchedule\n7- Exit\nYour Choice: ";
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
    //bool loop = true;
    int choice = 0;
    //int input = 0;
    MinMax myHeap;
    std::string a, b, c;

    while(inFile >> a)  {
     b = a.substr(a.find("(")+1, a.find(",")-1);
     c = a.substr(a.find(",")+1, a.find(")")-2);
     std::string d = c.substr(0, c.find(")"));
     //cout<<b<<", "<<d<<endl;
     myHeap.insert(stoi(b), stoi(d));
    //cout<<a<<" ";
    }
    inFile.close();
    myHeap.buildheap();
    while(true) {
      print();
      cin>>choice;
      while(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
      cout<<"Input a number not a leter\n";
      std::cin >> choice;
    }
      if(choice == 1) {
        std::string x;
        cout<<"Please input data in the correct format (int,int): \n";
        cin>>x;
        std::string l,k;
        l = x.substr(x.find("(")+1, x.find(",")-1);
        k = x.substr(x.find(",")+1, x.find(")")-2);
        std::string f = k.substr(0, k.find(")"));
        std::string test = "("+l+","+f+")";
        if(x != test) cout<<"Please input in the correct format.\n\n";
        else  myHeap.insert(stoi(l), stoi(f));
      }
      else if(choice == 2) {
        myHeap.deletemin();
      }
      else if(choice == 3) {
        myHeap.deletemax();
      }
      else if(choice == 4)  {
        myHeap.findmin();
      }
      else if(choice == 5)  {
        myHeap.findmax();
      }
      else if(choice == 6) {
        myHeap.runSchedule();
      }
      if(choice == 7) {
        cout<<"Bye bye!\n\n";
        return false;
      }
    }








  }

  return 0;
}
