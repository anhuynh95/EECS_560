#include "Node.h"
#include "Node.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "HashTable.h"
#include "HashTable.cpp"
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
  		int tempInt;
  		inFile>>tempInt;
  		HashTable table(tempInt);
  		while(inFile>> tempInt)
	    {
	    	table.Insert(tempInt);
	    }
  		int choice = 0;
  		bool loop = true;
  		
  		 while(loop)
  		 {
	  		cout<<"Please choose one of the following commands: \n"<<"1- Insert \n2- Delete\n3- Find\n4- Print\n5- Exit\n";
	  		cout<<"Your choice: ";
	  		cin>>choice;
  		 	if(choice == 1)
  		 	{
  		 		int temp =0;
  		 		cout<<"Enter a number to be inserted: ";
  		 		cin>>temp;
  		 		table.Insert(temp);
  		 	}
  		 	else if(choice == 2)
  		 	{
  		 		int temp =0;
  		 		cout<<"Enter a number to be deleted: ";
  		 		cin>>temp;
  		 		table.Delete(temp);
  		 	}
  		 	else if(choice == 3)
  		 	{
  		 		int temp =0;
  		 		cout<<"Enter a number to find: ";
  		 		cin>>temp;
  		 		table.Find(temp);
  		 	}
  		 	else if(choice == 4) table.Print();
  		 	else if(choice == 5)
  		 	{
  		 		cout<<"Bye Bye\n";
  		 		loop = false;
  		 	} 
  		 }
    }

  return 0;
}
