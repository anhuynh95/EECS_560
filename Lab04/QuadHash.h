#ifndef QUAD_HASH_H
#define QUAD_HASH_H
#include <string>
class QuadHash{
	public:
		QuadHash(int x);
		~QuadHash();

		void Insert(std::string);
		void Insert2(std::string, int y);
		void Delete(std::string x);
		void Print();
		bool Find(std::string x);
		void FindPalindrome();
		void ReverseString(int x);
		int Hash(std::string x, int y);
		void Rehash();
	private:
		int findNextPrime(int x);
		std::string findReverse(std::string x);
		bool isOn(std::string x);
		std::string* bucket;
		int size;
		int elementNum;
		bool* isEmpty;
		bool* isReversed;
};
#endif
