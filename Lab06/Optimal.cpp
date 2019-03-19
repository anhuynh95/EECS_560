#include "Optimal.h"

using namespace std;

Optimal::Optimal(int s)
{
  size = s;
   m_word = new std::string[size];
   m_data = new std::string[size];
   tree = new std::string[size];
   for(int i=0;i<size;i++){
     m_word[i] = "";
     m_data[i] = "";
   }
}
Optimal::~Optimal()
{
     delete[] this->c;
     delete[] this->t;
     delete[] this->p;
     delete[] this->m_word;
     delete[] this->tree;
     delete[] this->m_data;
}

bool Optimal::isOnData(std::string w)  {
  bool check = false;
  for(int i =0; i<=count; i++)  {
    if(m_data[i] == w)  {
      check = true;
      break;
    }
  }
  return check;
}

int Optimal::findValue(std::string w)  {
  int val, result;
  for(int i=0; (unsigned)i<w.length(); i++) {
    val = w[i];
    result = result + val;
  }
  return result;
}

void Optimal::sort()  {
  for(int i=0;i<m_size;i++)
	{
		 for(int j=i+1;j<m_size;j++)
		 {
			 if(findValue(m_data[i]) > findValue(m_data[j]))
			 {
        std::string temp = m_data[i];
				m_data[i]=m_data[j];
				m_data[j]=temp;
			}
		}
	 }
}
float Optimal::findProb(std::string w)  {
  int cnt = 0;
  for(int i=0; i<size; i++){
    if(w == m_word[i]){
      cnt = cnt+1;
    }
  }
  return float(cnt)/float(size);
}

void Optimal::processData() {
  m_data[0] = m_word[0];
  for(int i =1; i<size; i++){
    if(!isOnData(m_word[i]))
    {
      count++;
      m_data[count] = m_word[i];
    }
  }
  m_size = count+1;
  sort();
  p = new float[m_size];
  c = new float*[m_size];
  t = new int*[m_size];

  for(int i =0; i<m_size; i++){
   p[i] = findProb(m_data[i]);
    c[i] = new float[m_size];
    t[i] =  new int[m_size];
  }
  for(int i =0; i<m_size; i++){
    for(int j =0; j<m_size; j++)  {
      c[i][j] = 0;
      t[i][j] = 0;
    }
  }
}

bool Optimal::Insert(std::string wo){
   bool check = true;
  m_word[numberOfWords] = wo;
  numberOfWords++;
   return check;
}

float Optimal::findSum(int x, int y)  {
  float sum =0;
  for(int i = x; i<= y; i++)
    sum += p[i];

  return sum;
}


 float Optimal::Run() {
   processData();
   int k_min =0;
  for(int i = 0; i<m_size; i++){
    c[i][i] = p[i];
    t[i][i] = i+1;
  }

  for(int l = 2; l<=m_size; l++)  {
   for(int i=0; i<=m_size-l; i++) {
       int j = i+l-1;
      c[i][j] = 999999999;
      for(int k=i; k<= j; k++)  {
        float val = ((k > i)? c[i][k-1]:0) + ((k < j)? c[k+1][j]:0) + findSum(i, j);
        if (val < c[i][j]) {
          c[i][j] = val;
          k_min = k;
        }
        t[i][j] = k_min+1;
        }
      }
    }
  count = 0;
      minCost = c[0][m_size-1];
      return c[0][m_size-1];
 }


void Optimal::buildTree(int i, int j){
 if (j < i){
   return;
 }
  m_tree.Insert(t[i-1][j-1], m_data[t[i-1][j-1]-1]);
  count++;
  buildTree(i,t[i-1][j-1]-1);	// print left subtree
  buildTree(t[i-1][j-1]+1,j);	// print right subtree
}

void Optimal::Printsam()  {
  m_tree.printTree();
}

float Optimal::getCost()  {
  return minCost;
}

int Optimal::getMySize()  {
  return m_size;
}
