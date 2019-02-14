#include "DoubHash.h"
#include <iostream>
using namespace std;
DoubHash::DoubHash(int x)
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

DoubHash::~DoubHash()
{
	delete[] bucket;
	delete[] isEmpty;
	delete[] isReversed;
	size =0;
	elementNum = 0;
}

int DoubHash::Hash(std::string x, int y)
{
	int sum =0;
	int a =0;
	int position;
	int length = x.length();
	if(length > 8){
		length = 8;
	}
	char temp[length];
	for(int i = 0; i <length; i++)
  	{
  		temp[i] = x[i];
  	}
  	for(int i =0; i<length; i++)
  	{
  		int mul =1;
  		for(int j=0; j<i; j++)
  		{
  			mul = mul*10;
  		}
  		a = int(temp[i])*mul;
  		sum = sum+a;
  	}
  	position = (sum+y)%size;
  	return position;

}

int DoubHash::findValue(std::string x)
{
	int sum =0;
	int a =0;
	int length = x.length();
	if(length > 8){
		length = 8;
	}
	char temp[length];
	for(int i = 0; i <length; i++)
  	{
  		temp[i] = x[i];
  	}
  	for(int i =0; i<length; i++)
  	{
  		int mul =1;
  		for(int j=0; j<i; j++)
  		{
  			mul = mul*10;
  		}
  		a = int(temp[i])*mul;
  		sum = sum+a;
  	}
  	return sum;
}

void DoubHash::Print()
{
	cout<<"Double hashing: \n\n";
	for(int i =0; i<size; i++)
	{
		if(bucket[i]!="")
		cout<<i<<": "<<bucket[i]<<endl;
	}
	cout<<endl;
}

bool DoubHash::isOn(std::string x)
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

void DoubHash::Insert(std::string x)
{
	
	if(isOn(x) == true)
	{
		cout<<"Double probing: "<<x<<" is duplicated, can’t be added to the hash table\n";
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
				cout<<"Double probing: "<<x<<" is inserted into the hash table\n";
			}
			else
			{
				bool check = false;
				int hx = 5-(findValue(x)%5);
				for(int i=1; i<=elementNum; i++)
				{
					int pos = (Hash(x, 0) + i*hx)%size;
					if(isEmpty[pos] == true)
					{
						bucket[pos] = x;
						isEmpty[pos] = false;
						check = true;
						cout<<"Double probing: "<<x<<" is inserted into the hash table\n";
						break;

					}
				}
				if(check == false)
				{
					elementNum--;
					cout<<"Double probing: Insert failed.\n";
				}
			}
		}
		
	}
}

void DoubHash::Insert2(std::string x, int y)
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
			int hx = 5-(findValue(x)%5);
			for(int i=1; i<=elementNum; i++)
			{
				int pos = (Hash(x, 0) + i*hx)%size;
				if(isEmpty[pos] == true)
				{
					bucket[pos] = x;
					isEmpty[pos] = false;
					elementNum = elementNum+y;
					break;

				}
			}
		}
}

void DoubHash::Delete(std::string x)
{
	if(isOn(x) == false)
	{
		cout<<"Double probing: "<<x<<" is not found.\n";
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
				cout<<"Double probing: "<<x<<" is deleted from the hash table.\n";
				break;
			}
		}
	}
}

void DoubHash::Find(std::string x)
{
	bool check = false;
	std::string result;
	for(int i =0; i<size; i++)
	{
		if(bucket[i] == x || (bucket[i] == findReverse(x) && isReversed[i]==true))
		{
			cout<<"Double probing: '"<<x<<"' is found at location "<<i<<endl;
			check = true;
			break;
		}
	}
	if(check == false)
	{
		cout<<x<<" is not found in the hash table.\n";
	}
	cout<<endl;
}

void DoubHash::FindPalindrome()
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

void DoubHash::ReverseString(int x)
{
	std::string temp = bucket[x];
	if(temp !="")
	{
		int end = bucket[x].length();
		
		cout<<"Double probing: String '"<<temp; 
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
		cout<<"There is no string at location "<<x<<" with Double probing.\n";
	}
	
}

std::string DoubHash::findReverse(std::string x)
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

int DoubHash::findNextPrime(int x)
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

void DoubHash::Rehash()
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
}