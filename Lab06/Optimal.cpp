#include "Optimal.h"
using namespace std;
Optimal::Optimal()
{
  c = new float*[size];
  p = new float[size];
  m_word = new std::string[size];
  tree = new std::string[size];
  t = new int*[size];
  for(int i=0;i<size;i++){
    c[i] = new float[size];
    t[i] =  new int[size];
  }

}
Optimal::~Optimal()
{
    delete[] this->c;
    delete[] this->t;
    delete[] this->p;
    delete[] this->m_word;
    delete[] this->tree;
}

bool Optimal::Insert(std::string wo){
  bool check = false;
  for(int i =0; i<size; i++){
    if(m_word[i] == wo) check = true;
    break;
  }
  if(check == false)  {
    if(wo == "be")  {
      m_word[0] = "be";
      p[0] = 0.333;
    }
    else if(wo == "or") {
      m_word[1] = "or";
      p[1] = 0.167;
    }
    else if(wo == "to") {
      m_word[2] = "to";
      p[2] = 0.333;
    }
    else if(wo == "not")  {
      m_word[3] = "not";
      p[3] = 0.167;
    }
    count++;
  }

   return check;
}

float Optimal::findSum(int x, int y)  {
  float sum =0;
  for(int i = x; i<= y; i++)
    sum += p[i];

  return sum;
}


float Optimal::Run() {
  for(int i = 0; i<size; i++){
    c[i][i] = p[i];
    t[i][i] = i+1;
  }

   for(int l = 2; l<=size; l++)  {
     for(int i=0; i<=size-l; i++) {
       int j = i+l-1;
        c[i][j] = 99999999;
       for(int k=i; k<= j; k++)  {
          float val = ((k > i)? c[i][k-1]:0) + ((k < j)? c[k+1][j]:0) + findSum(i, j);
          if (val < c[i][j])
            c[i][j] = val;
            t[i][j] = k;
       }
     }
   }

   //implement for the tree
   tree[0] = m_word[t[0][3] - 1];
   tree[1] = m_word[t[0][1] -1];
   tree[2] = m_word[t[3][3] - 1];
   tree[3] = m_word[t[1][2] -1];
  minCost = c[0][size-1];
  return c[0][size-1];

}

void Optimal::Print(int pos){ //print in preorder
  if(pos > size-1) return;
  cout<<tree[pos]<<" ";
  Print(pos*2+1);
  Print(pos*2+2);
}

float Optimal::getCost()  {
  return minCost;
}
