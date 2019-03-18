#include <string>
#include <iostream>
#ifndef OPTIMAL_H
#define OPTIMAL_H
class Optimal
{
public:
  Optimal(int s);
  ~Optimal();
  bool Insert(std::string wo);
  void Print(int pos);
  float Run();
  float findSum(int x, int y);
  float getCost();
private:
  std::string* m_word;
  std::string* m_data;
  std::string* tree;
  float** c;
  float* p;
  int** t;
  int size;
  int m_size;
  int numberOfWords;
  int count;
  float minCost;
  void processData();
  bool isOnData(std::string w);
  float findProb(std::string w);
  void sort();
  void buildTreeLeft(int x, int y, int z);
  void buildTreeRight(int x, int y, int z);

};
#endif
