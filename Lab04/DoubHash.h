#ifndef DOUB_HASH_H
#define DOUB_HASH_H
#include <string>
class DoubHash{
	public:
		DoubHash(int x);
		~DoubHash();

		void Insert(std::string);
		void Insert2(std::string, int y);
		void Delete(std::string x);
		void Print();
		bool Find(std::string x);
		void FindPalindrome();
		void ReverseString(int x);
		int Hash(std::string x, int y);
		void Rehash();
		std::string findReverse(std::string x);
		int findValue(std::string x);
	private:
		int findNextPrime(int x);

		bool isOn(std::string x);
		std::string* bucket;
		int size;
		int elementNum;
		bool* isEmpty;
		bool* isReversed;
};
#endif
