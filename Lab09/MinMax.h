#ifndef MINMAX_H
#define MINMAX_H
#include <iostream>
#include <string>

class MinMax {
public:
  MinMax();
  ~MinMax();

  void buildheap();
  void insert(int x, int y);
  void deletemin();
  void findmin();
  void deletemax();
  void findmax();
  void runSchedule();

private:
  void buildData(int a, int b, std::string c, bool d);
  int findLastParent();
  int findMinChild(int x);
  int findMaxChild(int x);
  void mySwap(int x, int y);
  void printChild(int index);
  void myDel(int x);
  void myPrint();
  void collectData(int pri, int time);
  std::string * result;
  int rsize;
  int * priority;
  int * time;
  std::string * name;
  bool * check;
  int * deadpri;
  std::string * deadname;
  int size;
  int deadsize;
  int * deadtime;
//  std::string * unfinish;
  //int unsize;
};
#endif
