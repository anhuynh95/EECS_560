#include "Optimal.h"
using namespace std;
Optimal::Optimal(int s)
{
  size = s;
  // c = new float*[size];
  // p = new float[size];
   m_word = new std::string[size];
   m_data = new std::string[size];
   for(int i=0;i<size;i++){
     m_word[i] = "";
     m_data[i] = "";
   }
  // tree = new std::string[size];
  // t = new int*[size];
  // for(int i=0;i<size;i++){
  //   c[i] = new float[size];
  //   t[i] =  new int[size];
  // }
}
Optimal::~Optimal()
{
    // delete[] this->c;
    // delete[] this->t;
    // delete[] this->p;
    // delete[] this->m_word;
    // delete[] this->tree;
    //delete[] this->m_data;
}

bool Optimal::isOnData(std::string w)  {
  bool check = false;
  for(int i =0; i<count; i++)  {
    if(m_data[i] == w)  {
      check = true;
      break;
    }
  }
  return check;
}
void Optimal::sort()  {
  for(int i=0;i<m_size;i++)
	{
		 for(int j=i+1;j<m_size-1;j++)
		 {
       int x = m_data[i].compare(m_data[j]);
			 if(x>1)
			 {
        std::string temp = m_data[i];;
				m_data[i]=m_data[j];
				m_data[j]=temp;
      //  cout<<"luil"<<endl;
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
      //cout<<count<<endl;
    }
  }
  m_size = count+1;
  //cout<<"size: "<<m_size<<endl;
  sort();
  //find the values for each word
  p = new float[m_size];
  c = new float*[m_size];
  t = new int*[m_size];
  tree = new std::string[size];
  for(int i =0; i<m_size; i++){
   p[i] = findProb(m_data[i]);
    c[i] = new float[size];
    t[i] =  new int[size];
  }
  for(int i =0; i<m_size; i++){
    for(int j =0; j<m_size; j++)  {
      c[i][j] = 0;
      t[i][j] = 0;
    }
  }


}


bool Optimal::Insert(std::string wo){
   bool check = false;
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
  for(int i = 0; i<m_size; i++){
    c[i][i] = p[i];
    t[i][i] = i+1;
  }

  for(int l = 2; l<=m_size; l++)  {
   for(int i=0; i<=m_size-l; i++) {
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
//
//    //implement for the tree
  count = 0;
  //tree[0] = m_data[t[0][m_size-1]-1];
  //tree[2] = m_data[t[m_size/2][m_size-1]];
  //for(int i = 0; i<m_size; i++) {

  //for(int j =0; j<left; j++)  {
    //currentIndex = left;
    //if(i == left)
    //tree[i] = m_data[t[0][left]];

//  }

//}
  buildTreeLeft(1, m_size, 0);
  //tree[m_size-1] = m_data[t[m_size-1][m_size-1]-1];
  // buildTreeRight(1, m_size, 0);
      minCost = c[0][m_size-1];
      return c[0][m_size-1];
//

 }

 void Optimal::buildTreeLeft(int x, int y, int z)  {

     if(z >m_size) return;
     //if(!(x<=1 && y<=1)){
       cout<<x-1<<" "<<y-1<<" "<<z<<endl;
       count++;
    // }

    if(x<m_size/2) { // go left

    //tree[z] = m_data[t[x-1][y-1]-1];
     buildTreeLeft(x,y/2, z*2+1);
     buildTreeLeft(y, y/2+2, z+1);
   }
   // if(x>m_size) {
   //   buildTreeLeft(y, y/2+2, z+1);
   // }


 }

 void Optimal::buildTreeRight(int x, int y, int z)  {
   if(x > m_size || z > m_size) return;

   cout<<x-1<<" "<<y-1<<" "<<z<<endl;
   //cout<<m_data[t[x-1][y-1]-1]<<endl;
   //buildTreeRight(, y, z*2+2);
 }

void Optimal::Print(int pos){ //print in preorder
  // if(pos > m_size-1) return;
  // cout<<tree[pos]<<" ";
  // Print(pos*2+1);
  // Print(pos*2+2);
   for(int i=0; i<m_size; i++){
     //cout<<m_data[i]<<endl;
     //cout<<p[i]<<endl;
     //cout<<m_word[i]<<endl;
     cout<<tree[i]<<endl;

    for(int j=0; j<m_size; j++){
      //cout<<c[i][j]<<" ";
     //cout<<t[i][j]<<" ";
   }
   cout<<endl;
 }


  }

float Optimal::getCost()  {
  return minCost;
}
