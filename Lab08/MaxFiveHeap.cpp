#include "MaxFiveHeap.h"
#include <math.h>
using namespace std;

MaxFiveHeap::MaxFiveHeap(int* arr, int s)  {
  size = s;
  maxHeap = arr;
}

MaxFiveHeap::~MaxFiveHeap() {
}

int MaxFiveHeap::findLastParent()  {
  if(maxHeap[0] != 0) {
    return (floor(((size-1)-1)/5));
  }
  else  {
    return 0;
  }
}

int MaxFiveHeap::findLargestNodeinNextLevel(int index)  {
  int child = index*5+1;
  for(int i = 2; i<=5; i++) {
    int pos = index*5+i;
    if(maxHeap[pos] == 0) {
      return child;
    }
    if(maxHeap[child] < maxHeap[pos]) {
      child = pos;
    }
  }
  return child;
}

void MaxFiveHeap::buildheap() {
  bool check = true;
  while(check) {
    check = false;
    for(int i = findLastParent(); i>=0; i--) {
      if(maxHeap[i] < maxHeap[findLargestNodeinNextLevel(i)]) {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[findLargestNodeinNextLevel(i)];
        maxHeap[findLargestNodeinNextLevel(i)] = temp;
        check = true;
      }
    }
  }
}

void MaxFiveHeap::insert(int x) {
  maxHeap[size] = x;
  size++;
  buildheap();
  levelorder();
}


void MaxFiveHeap::printChild(int index) {
  for(int i = 1; i<= 5; i++)  {
    int child = 5*index+i;
    if(maxHeap[child] == 0) cout<<" ";
    else
    cout<<maxHeap[child]<<" ";
  }
}

void MaxFiveHeap::levelorder() {
  cout<<maxHeap[0]<<endl;
  printChild(0);
  cout<<endl;
  for(int i = 1; i<= findLastParent(); i++) {
    printChild(i);
    if( i!= findLastParent()) cout<<" - ";
    else cout<<endl;
  }
  cout<<endl;
}

void MaxFiveHeap::findmax()  {
  if(maxHeap[0] != 0) {
    cout<<"Min value is: "<<maxHeap[0]<<endl;
  }
  else  {
    cout<<"Empty heap\n";
  }
}

void MaxFiveHeap::findmin() {
  if(maxHeap[0] != 0) {
    int pos = floor((((size-1)-1)/5)+1);
    int temp = maxHeap[pos];

    for(int i = pos; i<size; i++)  {
      if(temp > maxHeap[i]) temp = maxHeap[i];
    }
    cout<<"Min value is: "<<temp<<endl;
  }
  else cout<<"Empty heap\n";
}

void MaxFiveHeap::deletemax() {
  if(maxHeap[0] != 0) {
    maxHeap[0] = maxHeap[size-1];
    maxHeap[size-1] =0;
    size--;
    buildheap();
    levelorder();
  }
  else cout<<"Empty Heap\n";
}

void MaxFiveHeap::deletemin() {
  if(maxHeap[0] != 0) {
    int temp = floor(((size-1-1)/5)+1);
    for(int i = temp; i<size; i++) {
      if(maxHeap[i]<maxHeap[temp])  temp = i;
    }
    maxHeap[temp] = maxHeap[size-1];
    maxHeap[size-1] = 0;
    size--;
    buildheap();
    levelorder();
  }
  else cout<<"Empty heap\n";
}
