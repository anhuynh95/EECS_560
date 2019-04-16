#include "MinFiveHeap.h"
#include <math.h>
using namespace std;

MinFiveHeap::MinFiveHeap(int* arr, int s)  {
  size = s;
  minHeap = arr;
}

MinFiveHeap::~MinFiveHeap() {
}

int MinFiveHeap::findLastParent()  {
  if(minHeap[0] != 0) {
    return (floor(((size-1)-1)/5));
  }
  else  {
    return 0;
  }
}

int MinFiveHeap::findSmallestNodeinNextLevel(int index)  {
  int child = index*5+1;
  for(int i = 2; i<=5; i++) {
    int pos = index*5+i;
    if(minHeap[pos] == 0) {
      return child;
    }
    if(minHeap[child] > minHeap[pos]) {
      child = pos;
    }
  }
  return child;
}

void MinFiveHeap::buildheap() {
  bool check = true;
  while(check) {
    check = false;
    for(int i = findLastParent(); i>=0; i--) {
      if(minHeap[i] > minHeap[findSmallestNodeinNextLevel(i)]) {
        int temp = minHeap[i];
        minHeap[i] = minHeap[findSmallestNodeinNextLevel(i)];
        minHeap[findSmallestNodeinNextLevel(i)] = temp;
        check = true;
      }
    }
  }
}

void MinFiveHeap::insert(int x) {
  minHeap[size] = x;
  size++;
  buildheap();
  levelorder();
}


void MinFiveHeap::printChild(int index) {
  for(int i = 1; i<= 5; i++)  {
    int child = 5*index+i;
    if(minHeap[child] == 0) cout<<" ";
    else
    cout<<minHeap[child]<<" ";
  }
}

void MinFiveHeap::levelorder() {
  cout<<minHeap[0]<<endl;
  printChild(0);
  cout<<endl;
  for(int i = 1; i<= findLastParent(); i++) {
    printChild(i);
    if( i!= findLastParent()) cout<<" - ";
    else cout<<endl;
  }
  cout<<endl;
}

void MinFiveHeap::findmin()  {
  if(minHeap[0] != 0) {
    cout<<"Min value is: "<<minHeap[0]<<endl;
  }
  else  {
    cout<<"Empty heap\n";
  }
}

void MinFiveHeap::findmax() {
  if(minHeap[0] != 0) {
    int temp =0;

    for(int i = floor((((size-1)-1)/5)+1); i<size; i++)  {
      if(temp < minHeap[i]) temp = minHeap[i];
    }
    cout<<"Min value is: "<<temp<<endl;
  }
  else cout<<"Empty heap\n";
}

void MinFiveHeap::deletemin() {
  if(minHeap[0] != 0) {
    minHeap[0] = minHeap[size-1];
    minHeap[size-1] =0;
    size--;
    buildheap();
    levelorder();
  }
  else cout<<"Empty Heap\n";
}

void MinFiveHeap::deletemax() {
  if(minHeap[0] != 0) {
    int temp = floor(((size-1-1)/5)+1);
    for(int i = temp; i<size; i++) {
      if(minHeap[i]>minHeap[temp])  temp = i;
    }
    minHeap[temp] = minHeap[size-1];
    minHeap[size-1] = 0;
    size--;
    buildheap();
    levelorder();
  }
  else cout<<"Empty heap\n";
}
