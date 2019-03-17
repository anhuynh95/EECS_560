#include <string>
#include <iostream>
#ifndef OPTIMAL_H
#define OPTIMAL_H
class Optimal
{
public:
  Optimal();
  ~Optimal();
  bool Insert(std::string wo);
  void Print(int pos);
  float Run();
  float findSum(int x, int y);
  float getCost();
private:
  std::string* m_word;
  std::string* tree;
  float** c;
  float* p;
  int** t;
  int size = 4;
  int count;
  float minCost;
};
#endif
