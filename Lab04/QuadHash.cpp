#include "QuadHash.h"
#include <iostream>
using namespace std;
QuadHash::QuadHash(int x)
{
	elementNum = 0;
	size = x;
	bucket =  new std::string[size];
	isEmpty = new bool[size];
	isReversed = new bool[size];
	for(int i =0; i<size; i++)
	{
		bucket[i] = "";
		isEmpty[i] = true;
		isReversed[i] = false;
	}
}

QuadHash::~QuadHash()
{
	delete[] bucket;
	delete[] isEmpty;
	delete[] isReversed;
	size =0;
	elementNum = 0;
}

int QuadHash::Hash(std::string x, int y)
{
		int position;
  	position = (std::stoi(x)+y)%size;
  	return position;

}

void QuadHash::Print()
{
	cout<<"Hash Table with Quadratic Probing:\n";
	for(int i =0; i<size; i++)
	{
		if(bucket[i]!="")
		cout<<i<<": "<<bucket[i]<<endl;
	}
	cout<<endl;
}

bool QuadHash::isOn(std::string x)
{
	bool check = false;
	for(int i =0; i<size; i++)
	{
		if(bucket[i] == x)
		{
			check = true;
			break;
		}
	}
	return (check);
}

void QuadHash::Insert(std::string x)
{

	if(isOn(x) == true)
	{
		cout<<"Quadratic probing: "<<x<<" is duplicated, can’t be added to the hash table\n";
	}
	else
	{
		elementNum++;
		float lamda = float(elementNum)/float(size);
		if(lamda >0.5)
		{
			Rehash();
			Insert2(x, 1);
			Print();
		}
		else
		{
			int position = Hash(x,0);
			if(isEmpty[position] == true)
			{
				bucket[position] = x;
				isEmpty[position] = false;
				cout<<"Quadratic probing: "<<x<<" is inserted into the hash table\n";
			}
			else
			{
				bool check = false;
				for(int i=1; i<=20; i++)
				{
					if(isEmpty[Hash(x,i*i)] == true)
					{
						bucket[Hash(x,i*i)] = x;
						isEmpty[Hash(x,i*i)] = false;
						check = true;
						cout<<"Quadratic probing: "<<x<<" is inserted into the hash table\n";
						break;

					}
				}
				if(check == false)
				{
					elementNum--;
					cout<<"Quadratic probing: Insert failed.\n";
				}
			}
		}

	}
}

void QuadHash::Insert2(std::string x, int y)
{
		int position = Hash(x,0);
		if(isEmpty[position] == true)
		{
			bucket[position] = x;
			isEmpty[position] = false;
			elementNum = elementNum+y;
		}
		else
		{
			for(int i=1; i<=elementNum; i++)
			{
				if(isEmpty[Hash(x,i*i)] == true)
				{
					bucket[Hash(x,i*i)] = x;
					isEmpty[Hash(x,i*i)] = false;
					elementNum = elementNum+y;
					break;
				}
			}
		}
}

void QuadHash::Delete(std::string x)
{
	if(isOn(x) == false)
	{
		cout<<"Quadratic probing: "<<x<<" is not found.\n";
	}
	else
	{
		for(int i =0; i<size; i++)
		{
			if(bucket[i]==x)
			{
				bucket[i] = "";
				isEmpty[i] = true;
				elementNum--;
				cout<<"Quadratic probing: "<<x<<" is deleted from the hash table.\n";
				break;
			}
		}
	}
}

bool QuadHash::Find(std::string x)
{
	bool check = false;
	std::string result;
	for(int i =0; i<size; i++)
	{
		if(bucket[i] == x)
		{
			cout<<"Quadratic probing: "<<x<<" is found at location "<<i<<endl;
			check = true;
			break;
		}
	}
	if(check == false)
	{
		cout<<"Quadratic probing: "<<x<<" is not found in the hash table.\n";
		return false;
	}
	else return true;
}

void QuadHash::FindPalindrome()
{
	cout<<"Palindrome strings: ";
	for(int i =0; i<size; i++)
	{
		int start =0;
		int end = bucket[i].length()-1;
		std::string temp = bucket[i];
		bool check = true;
		if(temp!="")
		{
			while (start < end)
			{
				if(temp[start]!=temp[end])
				{
					check = false;
				}
				start++;
				end--;
			}
			if(check == true)
			{
				cout<<temp<<" ";
			}
		}
	}
	cout<<endl<<endl;

}

void QuadHash::ReverseString(int x)
{
	std::string temp = bucket[x];
	if(temp !="")
	{
		int end = bucket[x].length();

		cout<<"Quadratic probing: String '"<<temp;
		for(int i=0; i<end/2; i++)
		{
			char temp1 = temp[end-1];
			temp[end-1] = temp[i];
			temp[i] = temp1;
		}
		bucket[x] = temp;
		isReversed[x] = true;
		cout<<"' is changed to '"<<temp<<"'\n";;
	}
	else
	{
		cout<<"There is no string at location "<<x<<" with Quadratic probing.\n";
	}

}

std::string QuadHash::findReverse(std::string x)
{
	std::string temp = x;
	if(temp !="")
	{
		int end = temp.length();
		for(int i=0; i<end/2; i++)
		{
			char temp1 = temp[end-1];
			temp[end-1] = temp[i];
			temp[i] = temp1;
		}
	}
	return (temp);
}

int QuadHash::findNextPrime(int x)
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

void QuadHash::Rehash()
{
	int newSize = findNextPrime(size*2);
	std::string* backup = new std::string[elementNum];
	int count=0;
	for(int i=0; i<size; i++)
	{
		if(bucket[i]!="")
		{
			backup[count] = bucket[i];
			count++;
		}
	}
	size = newSize;
	bucket = new std::string[size];
	isEmpty = new bool[size];
	for(int i=0; i<size; i++)
	{
		bucket[i]="";
		isEmpty[i] = true;
	}
	for(int i=0; i<elementNum; i++)
	{
		std::string temp = backup[i];
		Insert2(temp,0);
	}
	cout<<"Rehashing....\n\n";
}
