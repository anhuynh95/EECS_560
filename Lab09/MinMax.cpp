#include "MinMax.h"
#include <math.h>
using namespace std;

MinMax::MinMax()  {
  priority = new int[500];
  time = new int[500];
  name = new std::string[500];
  check = new bool[500];
  deadpri = new int[500];
  deadname = new std::string[500];
  deadtime = new int[500];
  result = new std::string[500];
  rsize = 0;
  //unfinish = new std::string[500];
  size =0;
  deadsize=0;
  //unsize = 0;
}

MinMax::~MinMax() {
  delete[] priority;
  delete[]  time;
  delete[]  name;
  delete[]  check;
  size =0;
}

int MinMax::findLastParent()  {
  if(size==0) return 0;
  else return(floor((size)/2)-1);
}

void MinMax::buildData(int a, int b, std::string c, bool d) {
  priority[size] = a;
  time[size] =b;
  name[size]  =c;
  check[size] =d;
}

void MinMax::collectData(int pri, int time) {
  std::string a = "P"+ to_string(size+1);
  buildData(pri, time, a, true);
  size++;
}

int MinMax::findMinChild(int x)  {
  int index = x*2;
  if(priority[index] == 0) {
    return(x);
  }

  int a = findMinChild(index);
  if(priority[index+1] != 0) {
    int b = findMinChild(index +1);
    if(priority[index] > priority[b]) {
      index = b;
    }
    else if(priority[index] == priority[b]) {
      if(time[index] > time[b]) {
        index = b;
      }
    }
  }
  if(priority[index] > priority[a]) {
    index = a;
  }
  else if(priority[index] == priority[a]) {
    if(time[index] > time[a]) {
      index = a;
    }
  }
  if(priority[index] > priority[x]) {
    index = x;
  }
  else if(priority[index] == priority[x]) {
    if(time[index] > time[x]) {
      index = x;
    }
  }
  return index;

}

int MinMax::findMaxChild(int x)  {
  int index = x*2;
  if(priority[index] == 0) {
    return(x);
  }

  int a = findMaxChild(index);
  if((priority[index+1] != 0) && ((index) < size)) {
    int b = findMaxChild(index +1);
    if((priority[index] < priority[b]) && ((index+1) <= size)) {
      index = b;
    }
    else if(priority[index] == priority[b]) {
      if(time[index] < time[b]) {
        index = b;
      }
    }
  }
  if(priority[index] < priority[a]) {
    index = a;
  }
  else if(priority[index] == priority[a]) {
    if(time[index] < time[a]) {
      index = a;
    }
  }
  if(priority[index] < priority[x]) {
    index = x;
  }
  else if(priority[index] == priority[x]) {
    if(time[index] < time[x]) {
      index = x;
    }
  }
  return index;

}

void MinMax::mySwap(int x, int y) {
  int a;
  std::string b;

  a = priority[x];
  priority[x] = priority[y];
  priority[y] = a;

  a = time[x];
  time[x] = time[y];
  time[y] = a;

  b = name[x];
  name[x] = name[y];
  name[y] = b;

}

void MinMax::buildheap()  {
   bool m = true;
    while(m)  {
       m = false;

       for(int i =findLastParent(); i > 0; i--)  {

        int type;
      if(i != 0) type = int(floor(log2(i+1))) % 2;
      else  type = 0;
      //cout<<floor(i/4)<<endl;
        //cout<<type<<" "<<name[i]<<endl;
        if(priority[0] > priority[1]) mySwap(0, 1);
        if(priority[0] > priority[2]) mySwap(0, 2);

       if(type == 0) {
         //cout<<i<<"LUL\n";
           if(priority[i] > priority[findMinChild(i)] && (findMinChild(i) % 2 == 0)) {
             mySwap(i, findMinChild(i));
            m = true;
           }
          else if(priority[i] == priority[findMinChild(i)]) {
            if(time[i] > time[findMinChild(i)])  {
              mySwap(i, findMinChild(i));
              m = true;
            }
          }
          if(priority[i] > priority[findMaxChild(i)]) {
            mySwap(i, findMaxChild(i));
            m = true;
          }
          else if(priority[i] == priority[findMaxChild(i)])  {
            if(time[i] > time[findMinChild(i)])  {
              mySwap(i, findMinChild(i));
              m = true;
            }
          }

       }
      else if(type == 1) {
        //  cout<<name[findMaxChild(i)]<<endl;
          if(priority[i] < priority[findMaxChild(i)])  {
            mySwap(i, findMaxChild(i));
            m = true;
          }
          else if(priority[i] == priority[findMaxChild(i)]) {
            if(time[i] < time[findMaxChild(i)])  {
              mySwap(i, findMaxChild(i));
              m = true;
            }
          }
          if(priority[i] < priority[findMinChild(i)]) {
            mySwap(i, findMinChild(i));
            m= true;
          }
          else if(priority[i] == priority[findMinChild(i)])  {
            if(time[i] < time[findMinChild(i)])  {
              mySwap(i, findMinChild(i));
              m = true;
            }
          }
        }


        //cout<<priority[int(floor((i-1)/4))]<<endl;



      }
    }

}

void MinMax::myDel(int x)  {
  priority[x] = 0;
  time[x] = 0;
  name[x] ="";
  check[x] = false;
}

void MinMax::deletemin()  {
  if(size == 0) {
    cout<<"The heap is empty.\n";
  }
  //only root
  else if(size == 1) {
    myDel(0);
    size--;
  }
  //2 node
  else if(size == 2) {
    mySwap(0, 1);
    myDel(1);
    size--;
  }
  //3 node
  else if(size == 3)  {
    if(priority[1] < priority[2]) {
      mySwap(0, 1);
      mySwap(1, 2);
      myDel(2);
      size--;
    }
    else if(priority[1] == priority[2])  {
      if(time[1] < time[2]) {
        mySwap(0, 1);
        mySwap(1, 2);
        myDel(2);
        size--;
      }
    }
    else  {
      mySwap(0, 2);
      myDel(2);
      size--;
    }
  }
  else  {
     int temp = size-1;
     int temp2 = size-1;
    for(int i = size-1; i > 0; i--) {
      //cout<<floor(i/4)<<endl;
       if((priority[temp] > priority[i]) && (floor(i/4) == 1)) {
         temp = i;
       }
      else if((priority[temp] == priority[i]) && (floor(i/4) == 1)) {
        if((time[temp] > time[i])) {
          temp = i;
        }
      }
    }
    if(temp2 <= temp)  {
      mySwap(0, temp2);
      myDel(temp2);
      size--;
      buildheap();
    }
     else  {
      mySwap(0, temp);
      mySwap(temp, temp2);
      myDel(temp2);
      size--;
      buildheap();
    }


  }
}

void MinMax::deletemax() {
  if(size == 0) {
    cout<<"The heap is empty.\n";
  }
  //only root
  else if(size == 1) {
    myDel(0);
    size--;
  }
  //2 node
  else if(size == 2) {
    //mySwap(0, 1);
    myDel(1);
    size--;
  }
  //3 node
  else if(size == 3)  {
    if(priority[1] > priority[2]) {
      mySwap(1, 2);

      myDel(2);
      size--;
    }
    else if(priority[1] == priority[2])  {
      if(time[1] > time[2]) {

        mySwap(1, 2);
        myDel(2);
        size--;
      }
    }
    else  {

      myDel(2);
      size--;
    }
  }
  else  {
    int z;
    if(priority[1]>priority[2]) z =1;
    else z =2;
    int temp = size-1;
    int temp2 = size-1;
    for(int i = size-1; i > 0; i--) {
      //cout<<floor((i+1)/4)-1<<endl;
        int type = int(floor(log2(i+1))) % 2;
    //cout<<priority[temp]<<"<"<<priority[i]<<endl;
        if((priority[temp] < priority[i]) && (type  == 1)) {
          temp = i;
        }
      else if((priority[temp] == priority[i]) && (type == 1)) {
        if((time[temp] < time[i])) {
          temp = i;
        }
      }

    }
    //cout<<temp<<" "<<priority[temp]<<endl;
    //cout<<name[temp]<<endl;
    if(temp2 <= temp)  {
      mySwap(z, temp2);
      myDel(temp2);
      size--;
      buildheap();
    }
     else  {
      mySwap(z, temp2);
      //mySwap(temp, temp2);
      myDel(temp2);
      size--;
      buildheap();
    }


  }
}

void MinMax::insert(int x, int y) {
  collectData(x, y);
  buildheap();
}

void MinMax::printChild(int index) {
  for(int i = 1; i<= 2; i++)  {
    int child = 2*index+i;
    if(name[child] == "") cout<<" ";
    else
    cout<<name[child]<<" ";
  }
}

void MinMax::findmin() {
  if(size == 0) cout<<"The heap is empty.\n";
  else  {
    cout<<name[0]<<"("<<priority[0]<<", "<<time[0]<<")\n";
  }
}

void MinMax::findmax()  {
  if(size == 0) cout<<"The heap is empty.\n";
  else  {
    if(priority[1] > priority[2]) {
      cout<<name[1]<<"("<<priority[1]<<", "<<time[1]<<")\n";
    }
    else if(priority[1] == priority[2]) {
      if(time[1] > time [2])  {
        cout<<name[1]<<"("<<priority[1]<<", "<<time[1]<<")\n";
      }
      else  {
        cout<<name[2]<<"("<<priority[2]<<", "<<time[2]<<")\n";
      }
    }
    else  {
      cout<<name[2]<<"("<<priority[2]<<", "<<time[2]<<")\n";
    }
  }
}

void MinMax::myPrint()  {
  if(size == 0) {
    cout<<"The heap is empty.\n";
  }
  else  {
    //cout<<"Updated Minmax heap: \n";
    cout<<name[0]<<endl;
    printChild(0);
    cout<<endl;
    for(int i = 1; i<= findLastParent(); i++) {
      printChild(i);
      if( i < findLastParent()-1) cout<<" - ";
      else if(i == findLastParent()) cout<<endl;
    }
  cout<<endl;
}
}

void MinMax::runSchedule()  {
  bool loop = false;
  int min = 20;
  int max = 10;
  int cnt = 1;

  int x;
  cout<<"\nInitial Minmax heap: \n";
  myPrint();
  cout<<"Scheduling output: \n\n";
  while(size != 0)  {
    if((cnt-1)%2 == 0){
      //deadtime[cnt] = time[0];
      x = time[0];
      std::string unfinish = "";

      for(int i=0;  i<min; i++) {
        x--;
        if(x == 0 && (i<=19)) { //use all time

          deadname[deadsize] = name[0];
          //cout<<"lul\n";
          deadpri[deadsize] = priority[0];
          deadtime[deadsize] = 0;
          deadsize++;
          result[rsize] = name[0];
          rsize++;
          deletemin();
          x = time[0];

        }
        if(x > 0 && (i == 19))  {// didnt finish
          time[0] = x;
          unfinish = name[0];


        }
        if(i == 19) loop = true;
      }


      cout<<"T"<<cnt<<": 20 ms\n";
      for(int i =0; i<deadsize; i++)  {
        cout<<deadname[i]<<"("<<deadpri[i]<<", "<<deadtime[i]<< ")";
        if(i <= deadsize-1)  cout<<", ";
        //if(i == deadsize-1) cout<<" ";
      }
      if(unfinish == name[0] && size!=0) cout<<unfinish<<"("<<priority[0]<<", "<<time[0]<< ")\n";
      else cout<<endl;
      //else
      for(int i =0; i<deadsize; i++)  {
        cout<<deadname[i];
        if(i == deadsize-1) cout<<" and ";
        else cout<<", ";
      }
      if(unfinish == name[0]) cout<<unfinish;
      //nfinish = "";
      cout<<" are executed. ";
      for(int i=0; i<deadsize; i++) {
        if(deadtime[i] == 0){
          cout<<deadname[i];
          if(i == deadsize-2) cout<<" and ";

          else if(i < deadsize-2) cout<<", ";
        }
      }
      if(deadsize>1) cout<<" are completed and removed from heap\n\n";
      else  cout<<" are completed and removed from heap\n\n";
      for(int i=0; i<deadsize; i++) {
        deadname[i] = "";
        deadpri[i] = 0;
        deadtime[i] = 0;
      }

      //deletemin();
      //loop = true;
      deadsize = 0;
    }
    if((cnt-1)%2 == 1){
      int k;
      if(priority[1] > priority[2]) k = 1;
      else k = 2;

      x = time[k];
      std::string unfinish ="";

      for(int i=0;  i<max; i++) {
        x--;

        if(x == 0 && (i<=9)) { //use all time
          if(priority[1] > priority[2]) k = 1;
          else k = 2;
          deadname[deadsize] = name[k];
          //cout<<"lul\n";
          deadpri[deadsize] = priority[k];
          deadtime[deadsize] = 0;
          deadsize++;
          result[rsize] = name[k];
          rsize++;
          deletemax();

          x = time[k];
        }

        if(x > 0 && (i == 9))  {// didnt finish
          time[k] = x;
          unfinish = name[k];

        }
        if(i == 9)  loop = true;
      }


      cout<<"T"<<cnt<<": 10 ms\n";
      for(int i =0; i<deadsize; i++)  {
        cout<<deadname[i]<<"("<<deadpri[i]<<", "<<deadtime[i]<<")";
        if(i<=deadsize-1)  cout<<", ";

      }

      if(unfinish == name[k] && size!=0)  cout<<unfinish<<"("<<priority[k]<<", "<<time[k]<< ")\n";
      else  cout<<endl;

      for(int i =0; i<deadsize; i++)  {
        cout<<deadname[i];
        if(i < deadsize-1) cout<<", ";
        if(i == deadsize-1) cout<<" and ";
      }
      if(unfinish == name[k]) cout<<unfinish<<" are executed. ";

      else cout<<" is executed. ";
      std::string g;
      for(int i=0; i<deadsize; i++) {
        if(deadtime[i] == 0){
          g= deadname[i];
          cout<<deadname[i];
          if(i == deadsize) cout<<" and ";

          else if(i < deadsize-1) cout<<", ";
        }
      }
      if(unfinish != name[k]) cout<<" are completed and removed from heap\n\n";
      //else if()
      if(g == "") cout<<"None is completed and removed from heap\n\n";
      else  cout<<" is completed and removed from heap\n\n";
      for(int i=0; i<deadsize; i++) {
        deadname[i] = "";
        deadpri[i] = 0;
        deadtime[i] = 0;
      }
      deadsize = 0;
      //loop = true;

    }
    if(loop)  cnt++;
    cout<<"Updated Minmax heap: \n";
    myPrint();
  }
  cout<<"\nScheduling order: \n";
  for(int i = 0; i<rsize; i++)  {
    cout<<result[i]<<" ";
  }
  cout<<endl;

}
