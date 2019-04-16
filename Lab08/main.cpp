#include "MinFiveHeap.h"
#include "MaxFiveHeap.h"
#include <iostream>
#include <fstream>
using namespace std;

void print()  {
  cout<<"Please choose one of the following commands:\n1- Insert\n2- DeleteMin\n3- DeleteMax\n4- FindMin\n5- FindMax\n6- LevelOrder\n7- Exit\nYour Choice: ";
}


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
    bool loop = true;
    int choice = 0;
    int input = 0;
    int cnt = 0;
    int minActivate =0;
    int heap[500];
    for(int i =0; i<500; i++) {
      heap[i] = 0;
    }
    while(inFile >> input)  {
      heap[cnt] = input;
      cnt++;
    }
    inFile.close();

    cout<<"\nPlease choose your heap type:\n1. Min-5 Heap\n2. Max-5 Heap\nYour choice: ";
    cin>>minActivate;
    while(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
      std::cin >> minActivate;
    }
    if(minActivate == 1)  {
      MinFiveHeap myMin(heap, cnt);
      myMin.buildheap();
      while(loop) {
        print();
        cin>>choice;
        while(std::cin.fail())
        {
          std::cin.clear();
          std::cin.ignore();
          std::cin >> choice;
        }
        if(choice == 1) {
          int x;
          cout<<"Enter a value to be inserted: ";
          cin>>x;
          while(std::cin.fail())
          {
            std::cin.clear();
            std::cin.ignore();
            cout<<"Enter a value to be inserted: ";
            std::cin >> x;
          }
          myMin.insert(x);
        }
        else if(choice == 2) {
          myMin.deletemin();
        }
        else if(choice == 3) {
          myMin.deletemax();
        }
        else if(choice == 4) {
          myMin.findmin();
        }
        else if(choice == 5) {
          myMin.findmax();
        }
        else if(choice == 6) {
          myMin.levelorder();
        }
        else if(choice == 7) {
          cout<<"Byebye!\n\n";
          loop = false;
        }
        else cout<<"No option chosen.\n";

      }
    }
    else if(minActivate == 2) {
      MaxFiveHeap myMax(heap, cnt);
      myMax.buildheap();
      while(loop) {
        print();
        cin>>choice;
        while(std::cin.fail())
        {
          std::cin.clear();
          std::cin.ignore();
          std::cin >> choice;
        }
        if(choice == 1) {
          int x;
          cout<<"Enter a value to be inserted: ";
          cin>>x;
          while(std::cin.fail())
          {
            std::cin.clear();
            std::cin.ignore();
            cout<<"Enter a value to be inserted: ";
            std::cin >> x;
          }
          myMax.insert(x);
        }
        else if(choice == 2) {
          myMax.deletemin();
        }
        else if(choice == 3) {
          myMax.deletemax();
        }
        else if(choice == 4) {
          myMax.findmin();
        }
        else if(choice == 5) {
          myMax.findmax();
        }
        else if(choice == 6) {
          myMax.levelorder();
        }
        else if(choice == 7) {
          cout<<"Byebye!\n\n";
          loop = false;
        }
        else cout<<"No option chosen.\n";

      }
    }
    else cout<<"There is no other heap\n";

  }

  return 0;
}
