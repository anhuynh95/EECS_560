#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
#include "LinkedList.h"
class HashTable
{
public:
	HashTable(int x);
	~HashTable();
	void Insert(int x);
	void Delete(int x);
	void Print();
	int Hash(int x);
	void Rehash(int x);
	void Find(int x);

private:
	int size;
	int tempSize;
	int intNum;
	LinkedList* table;
	LinkedList* backup;
	int findNextPrime(int x);
};
#endif