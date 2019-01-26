#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  char choice =0;
  int tempInt =0;
  bool loop = true;
  LinkedList a;
  LinkedList b;
  ifstream inFile;
	inFile.open("data.txt");
  if(!inFile){
	   cout<<"Unable to open data.txt or the file is not in the same folder. \n";
	}
  else
  {
    while(inFile>> tempInt)
    {
     a.Insert(tempInt);
    }
    while(loop)
    {
      cout<<"\nChoose one operation from the options below: \n";
      cout<<" 1. Insert\n 2. Delete\n 3. Find Smallest number\n 4. Find Largest number\n";
      cout<<" 5. Average of numbers\n 6. Merge2Lists\n 7. Print\n 8. Exit\n Your choice: ";
      cin>>choice;
      ///////////////////CHOICES/////////////////////////////////////////
      if(choice == '1') //INSERT
      {
        int value = 0;
        cout<<"Enter element to be inserted in list: ";
        cin>>value;
        a.Insert(value);
      }
      ///DELETE
      else if(choice == '2')
      {
        int value =0;
        cout<<"Enter the number to be deleted: ";
        cin>>value;
        a.Delete(value);
      }
      //SMALLEST
      else if(choice == '3')
      {
        cout<<"Smallest number: "<<a.Smallest()<<"\n";
      }
      //LARGEST
      else if(choice == '4')
      {
        cout<<"Largest number: "<<a.Largest()<<"\n";
      }
      //AVERAGE
      else if(choice == '5')
      {
        cout<<"Average: "<<a.Average()<<"\n";
      }
      //MERGE
      else if(choice =='6')
      {
        int temp =0;
        int number =0;
        cout<<"How many numbers are there in your new list?: ";
        cin>>number;
        cout<<"Enter new list to be merged.\n ";
        for(int i=1; i<= number; i++)
        {
          cout<<number+1-i<<" numbers need to be inserted! \n Your"<<i<<" number: ";
          cin>>temp;
          b.Insert(temp);
        }
        a.Merge2Lists(b);
      }
      //PRINT
      else if(choice == '7') a.Print();
      //EXIT
      else if(choice == '8')
      {
        cout<<"Done!\n";
        loop = false;
      }
      //HANDLE BAD INPUTS
      else cout<<"Please enter a valid input.\n";
    }
  }
  return 0;
}
