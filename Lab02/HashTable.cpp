#include <iostream>
#include "HashTable.h"
using namespace std;

HashTable::HashTable(int x)
{
	size = x;
	intNum =0;
	table = new LinkedList[size];
	for(int i=0; i<size; i++)
	{
		table[i] = LinkedList();
	}
}

HashTable::~HashTable()
{
	size =0;
	tempSize =0;
	delete[] table;
	//delete[] tempTable;

	// for(int i=0; i<size; i++)
	// {
	// 	table[i] = LinkedList();
	// }
}

int HashTable::Hash(int x)
{
	return(x%size);
}



void HashTable::Rehash(int x)
{
	backup = new LinkedList[tempSize];
	for(int i=0; i<tempSize; i++)
	{
		while(!table[i].IsEmpty())
		{
			int temp = table[i].getFront();
			backup[i].Insert(temp);
			table[i].DeleteFront();
		}
	}
	size = x;
	table = new LinkedList[size];
	for(int i=0; i<size; i++)
	{
		table[i] = LinkedList();
	}

	for(int i=0; i<tempSize; i++)
	{
		while(!backup[i].IsEmpty())
		{
			int temp = backup[i].getFront();
			table[Hash(temp)].Insert(temp);
			backup[i].DeleteFront();
		}
	}
	cout<<"Hash table is rehashed.\n\n";
}

int HashTable::findNextPrime(int x)
{
	int i, count;
	for(i=x; 1; i++)
	{
		count =0;
		for(int j=2; j<i; j++)
		{
			if(i%j == 0)
			{
				count++;
				break;
			} 
		}
		if(count ==0) return i;
	}
}

void HashTable::Insert(int x)
{
	if(table[Hash(x)].isHere(x) == false)
	{
		double lamda = double(intNum)/double(size);
		if(lamda < 1)
		{
			table[Hash(x)].Insert(x);
			cout<<x<<" is added to the hash table\n\n";
			intNum++;
		}
		else
		{
			tempSize = size;
			Rehash(findNextPrime(size*2));
			table[Hash(x)].Insert(x);
		}
	}
	 else
	{
	 	cout<<x<<"  is a duplicate of "<<x<<" can’t be added to the hash table\n\n";
	}
}

void HashTable::Delete(int x)
{
	if(table[Hash(x)].isHere(x) == true)
	{
		table[Hash(x)].Delete(x);
		cout<<x<<" is removed from the hash table\n\n";
		intNum--;
	}
	else
	{
		cout<<x<<"  was not found\n\n";
	}
}

void HashTable::Print()
{
	for(int i=0; i<size; i++)
	{
		cout<<i<<":";
		table[i].Print();
	}
	cout<<"\n";
}

void HashTable::Find(int x)
{
	int position = Hash(x);
	if(table[Hash(x)].isHere(x) == true)
	{
		cout<<x<<" is found at location "<<position<<"\n";
	}
	else
	{
		cout<<x<<"  can’t be found in the hash table.\n";
	}
}