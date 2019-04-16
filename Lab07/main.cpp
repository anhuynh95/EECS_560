#include <iostream>
#include <fstream>
#include "Tree.h"

using namespace std;
bool isLegal(char x)  {
  if(x == 'A' || x == 'B' || x == 'C' || x == 'D' || x == 'E' || x == 'F' || x == 'G' ||
x == 'H' || x == 'I' || x == 'J' || x == 'K' || x == 'L' || x == 'M' || x == 'N'
|| x == 'O' || x == 'P' || x == 'Q' || x == 'R' || x == 'S' || x == 'T' || x == 'U' ||
 x == 'V' || x == 'W' || x == 'X' || x == 'Y' || x == 'Z')  {
   return true;
 }
 else {
   cout<<"Invalid Input\n";
   return false;
 }
}

void print();
int main()
{
  int choice;
  char myInput, myCheck, myMin, myMax;
  Tree treeObj;
  print();

  cin >> choice;
  while(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore();
    std::cin >> choice;
  }
  while(choice != 9){
        switch(choice){
                case 1: cout << "\nEnter character to be inserted" << endl;
                        cin >> myInput;
                        while(!isLegal(myInput)) {
                          cin >> myInput;
                        }
                        myCheck = treeObj.FindData(myInput);
                        if(myCheck != 0){
                                cout << "Insert was unsuccessful" << endl;
                        }
                        else{
                                treeObj.Insert(myInput);
                                cout << "Insert was successful" << endl;
                        }
                        break;
                case 2: cout << "\nEnter character to be deleted" << endl;
                        cin >> myInput;
                        while(!isLegal(myInput)) {
                          cin >> myInput;
                        }
                        myCheck = treeObj.FindData(myInput);
                        if(myCheck == 0){
                          cout << "Delete was unsuccessful" << endl;
                        }
                        else{
                          treeObj.Delete(myInput);
                          cout << "Delete was successful" << endl;
                        }
                        break;
                case 3: treeObj.DeleteMin();
                        break;
                case 4: treeObj.DeleteMax();
                        break;
                case 5: cout << "\nEnter character to be found" <<endl;
                        cin >> myInput;
                        myCheck = treeObj.FindData(myInput);
                        if(myCheck == 0) cout << "Character not found in tree" << endl;
                        else  cout << "Character is found in tree" << endl;
                        break;
                case 6: myMin = treeObj.FindMin();
                        if(myMin != 0)  cout <<myMin << endl;
                        else  cout << "The tree is empty" << endl;
                        break;
                case 7: myMax = treeObj.FindMax();
                        if(myMax != 0)  cout <<myMax << endl;
                        else  cout << "The tree is empty" << endl;
                        break;
                case 8: treeObj.LevelOrder();
                        break;
                default:
                        cout << "Invalid choice" << endl;
                }
        print();
        cin >> choice;
        while(std::cin.fail())
        {
          std::cin.clear();
          std::cin.ignore();
          std::cin >> choice;
        }

        cout << endl;
        }
        cout << "Bye Bye!!\n" << endl;
}

void print(){
   cout << "\n-----------------------------------------------------------"   << endl;
   cout << "Please choose one of the following commands"<< endl;
   cout << "1- Insert"<< endl;
   cout << "2- Delete"<< endl;
   cout << "3- DeleteMin"<< endl;
   cout << "4- DeleteMax"<< endl;
   cout << "5- Find"<< endl;
   cout << "6- FindMin"<<endl;
   cout << "7- FindMax"<<endl;
   cout << "8- Level Order Traversal"<<endl;
   cout << "9- Exit\n"<<endl;
}
