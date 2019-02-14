#include "QuadHash.h"
#include "QuadHash.cpp"
#include "DoubHash.h"
#include "DoubHash.cpp"
#include <iostream>
#include <fstream>
#include <string>
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
  		std::string temp;
  		inFile>>temp;
  		int qsize = std::stoi(temp);
  		QuadHash quad(qsize);
  		DoubHash doub(qsize);
  		while(inFile>> temp)
	    {
	    	 quad.Insert2(temp,1);
	    	 doub.Insert2(temp,1);
	    }
	    bool loop = true;
	    while(loop)
	    {
	    	cout<<"-------------------------------------------------\n";
		    cout<<"Please choose one of the following commands: \n";
		    cout<<"1- Insert\n2- Delete\n3- Find\n4- FindPalindrome\n5- ReverseString\n6- Print\n7- Exit\n";
		    cout<<"Your choice: \n";
		    int choice;
		    cin>>choice;
		    cout<<endl;
		    while(std::cin.fail())
		    {
		    	std::cout<<"Invalid input. Please enter one of the choice."<<endl;
		    	std::cin.clear();
		    	std::cin.ignore();
		    	cout<<"Your choice: \n";
		    	std::cin >> choice;
		    }
		    if(choice == 1)
		    {
		    	std::string input;
		    	cout<<"Enter a string to be inserted: \n";
		    	cin>>input;
		    	quad.Insert(input);
		    	doub.Insert(input);
		    	cout<<endl;
		    }
		    else if(choice == 2)
		    {
		    	std::string input;
		    	cout<<"Enter a string to be deleted: \n";
		    	cin>>input;
		    	quad.Delete(input);
		    	doub.Delete(input);
		    	cout<<endl;
		    }
		    else if(choice == 3)
		    {
		    	std::string input;
		    	cout<<"Enter a string to be found: \n";
		    	cin>>input;
		    	quad.Find(input);
		    	doub.Find(input);
		    }
		    else if(choice == 4)
		    {
		    	quad.FindPalindrome();
		    }
		    else if(choice == 5)
		    {
		    	int input;
		    	cout<<"Enter location of string you want to reverse: \n";
		    	cin>>input;
		    	quad.ReverseString(input);
		    	doub.ReverseString(input);
		    	cout<<endl;
		    }
		    else if(choice == 6)
		    {
		    	quad.Print();
		    	doub.Print();
		    }
		    else if(choice == 7)
		    {
		    	loop = false;
		    	cout<<"Done!\n";
		    }	
		    else	cout<<"Please pick one of those choice.\n\n";
	    }
	    

	    
  		
  }	
  return 0;
}