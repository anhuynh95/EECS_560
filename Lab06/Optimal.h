#include <string>
#include <iostream>
#include "BinarySearchTree.h"
#ifndef OPTIMAL_H
#define OPTIMAL_H
class Optimal
{
public:
  Optimal(int s);
  ~Optimal();
  bool Insert(std::string wo);
  void buildTree(int i, int j);
  void Printsam();
  float Run();
  float findSum(int x, int y);
  float getCost();
  int getMySize();
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
  int findValue(std::string w);
  BinarySearchTree m_tree;
};
#endif
