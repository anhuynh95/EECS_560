using namespace std;
Executive::Executive(){}

void Executive::run()
{

/*---------------------------BUILD AND FIND-------------------------------------*/
  HashTable openHash(m);
  QuadHash quadHash(m);
  DoubHash doubHash(m);
  double range = 0.0;
  double f_range =0.0;




  for(int k =0; k<5; k++)
  {
    range = range + 0.1;
    f_range = f_range+0.01;
    int i_size = floor(range*m); //change this
    int f_size = floor(f_range*m); //change this
    int i_num[i_size];
    int f_num[f_size];
    srand(time(NULL));
    for(int i=0; i<i_size; i++){
      i_num[i] = rand()%(5*m)+1;
    }
    for(int i=0; i<f_size; i++){
      f_num[i] = rand()%(5*m)+1;
    }
    if(k==4){
      for(int i =0; i< i_size; i++)
        {
          openHash.Insert(i_num[i]);
          quadHash.Insert(std::to_string(i_num[i]));
          doubHash.Insert(std::to_string(i_num[i]));
        }
    }
    for(int i=0; i<5; i++)
    {
     //OPEN HASH
     clock_t o_t = clock();
     HashTable hash(m);
     for(int i =0; i<i_size; i++)
     {
       hash.Insert(i_num[i]);
     }
     h_b_time[i] = double(clock()-o_t);
     int ha_s_find =0;
     int ha_u_find =0;
     for(int i =0; i< f_size; i++)
       {
         clock_t f_t= clock();
         hash.Find(f_num[i]);
         double temp = double(clock()-f_t); //end of clock

         if(hash.Find(f_num[i]) == true){
           ha_s_find = ha_s_find +temp;
         }
         else{
           ha_u_find = ha_u_find + temp;
         }
       }
       h_s_find[i] = ha_s_find;
       h_u_find[i] = ha_u_find;

     //QUAD HASH
     clock_t q_t= clock();
     QuadHash quad(m);
     for(int i =0; i<i_size; i++)
     {
       quad.Insert(std::to_string(i_num[i]));
     }
     q_b_time[i] = double(clock()-q_t);
     int qu_s_find =0;
     int qu_u_find =0;
     for(int i =0; i< f_size; i++)
       {
         clock_t q_f_t= clock();
         quad.Find(std::to_string(f_num[i]));
         double temp = double(clock()-q_f_t); //end of clock

         if(quad.Find(std::to_string(f_num[i])) == true){
           qu_s_find = qu_s_find +temp;
         }
         else{
           qu_u_find = qu_u_find + temp;
         }
       }
       q_s_find[i] = qu_s_find;
       q_u_find[i] = qu_u_find;

     //DOUB HASH
     clock_t d_t= clock();
     DoubHash doub(m);
     for(int i =0; i<i_size; i++)
     {
       doub.Insert(std::to_string(i_num[i]));
     }
     d_b_time[i] = double(clock()-d_t);
     int do_s_find =0;
     int do_u_find =0;

       for(int i =0; i< f_size; i++)
       {
         clock_t d_f_t= clock();
         doub.Find(std::to_string(f_num[i]));
         double temp = double(clock()-d_f_t); //end of clock

         if(doub.Find(std::to_string(f_num[i])) == true){
           do_s_find = do_s_find +temp;
         }
         else{
           do_u_find = do_u_find + temp;
         }
       }
       d_s_find[i] = do_s_find;
       d_u_find[i] = do_u_find;

    }
   a_h_b_time[k] = ((h_b_time[0]+h_b_time[1]+h_b_time[2]+h_b_time[3]+h_b_time[4])/5);
   a_q_b_time[k] = ((q_b_time[0]+q_b_time[1]+q_b_time[2]+q_b_time[3]+q_b_time[4])/5);
   a_d_b_time[k] = ((d_b_time[0]+d_b_time[1]+d_b_time[2]+d_b_time[3]+d_b_time[4])/5);

   a_h_s_find[k]=((h_s_find[0]+h_s_find[1]+h_s_find[2]+h_s_find[3]+h_s_find[4])/5);
   a_h_u_find[k]=((h_u_find[0]+h_u_find[1]+h_u_find[2]+h_u_find[3]+h_u_find[4])/5);
   a_q_s_find[k]=((q_s_find[0]+q_s_find[1]+q_s_find[2]+q_s_find[3]+q_s_find[4])/5);
   a_q_u_find[k]=((q_u_find[0]+q_u_find[1]+q_u_find[2]+q_u_find[3]+q_u_find[4])/5);
   a_d_s_find[k]=((d_s_find[0]+d_s_find[1]+d_s_find[2]+d_s_find[3]+d_s_find[4])/5);
   a_d_u_find[k]=((d_u_find[0]+d_u_find[1]+d_u_find[2]+d_u_find[3]+d_u_find[4])/5);
   }



/*-------------------------------USER INTERACTION-----------------------------*/
bool loop = true;
while(loop)
{
  cout<<"Please choose one of the following commands:\n1- Test HashTables\n2- Performance Comparison\n3- Exit\n";
  int choice;
  cin>>choice;
  cout<<endl;
  while(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore();
    std::cin >> choice;
  }
  if(choice == 1)
  {
     openHash.Print();
     quadHash.Print();
     doubHash.Print();
  }
  if(choice == 2)
  {
    cout<<"Performance (Open Hashing): \n";
      for(int i=0; i<4; i++)
      {
        for(int j =0; j<6; j++)
        {
          if(i==0 && j==0) cout<<"\t\t";
          else if(i==0 && j==1) cout<<"100,000\t\t";
          else if(i==0 && j==2) cout<<"200,000\t\t";
          else if(i==0 && j==3) cout<<"300,000\t\t";
          else if(i==0 && j==4) cout<<"400,000\t\t";
          else if(i==0 && j==5) cout<<"500,000\t\t";

          else if(i==1 && j==0) cout<<"Build\t\t";
          else if(i==2 && j==0) cout<<"Found\t\t";
          else if(i==3 && j==0) cout<<"Not Found\t";
          else if(i ==1 && j>0) cout<<a_h_b_time[j-1]<<"\t\t";
          else if(i==2 && j>0) cout<<a_h_s_find[j-1]<<"\t\t";
          else if(i==3 && j>0) cout<<a_h_u_find[j-1]<<"\t\t";
        }
        cout<<endl;
      }

      cout<<"Performance (Quadratic Probing): \n";
        for(int i=0; i<4; i++)
        {
          for(int j =0; j<6; j++)
          {
            if(i==0 && j==0) cout<<"\t\t";
            else if(i==0 && j==1) cout<<"100,000\t\t";
            else if(i==0 && j==2) cout<<"200,000\t\t";
            else if(i==0 && j==3) cout<<"300,000\t\t";
            else if(i==0 && j==4) cout<<"400,000\t\t";
            else if(i==0 && j==5) cout<<"500,000\t\t";

            else if(i==1 && j==0) cout<<"Build\t\t";
            else if(i==2 && j==0) cout<<"Found\t\t";
            else if(i==3 && j==0) cout<<"Not Found\t";
            else if(i ==1 && j>0) cout<<a_q_b_time[j-1]<<"\t\t";
            else if(i==2 && j>0) cout<<a_q_s_find[j-1]<<"\t\t";
            else if(i==3 && j>0) cout<<a_q_u_find[j-1]<<"\t\t";
          }
          cout<<endl;
        }

        cout<<"Performance (Double Hashing): \n";
          for(int i=0; i<4; i++)
          {
            for(int j =0; j<6; j++)
            {
              if(i==0 && j==0) cout<<"\t\t";
              else if(i==0 && j==1) cout<<"100,000\t\t";
              else if(i==0 && j==2) cout<<"200,000\t\t";
              else if(i==0 && j==3) cout<<"300,000\t\t";
              else if(i==0 && j==4) cout<<"400,000\t\t";
              else if(i==0 && j==5) cout<<"500,000\t\t";

              else if(i==1 && j==0) cout<<"Build\t\t";
              else if(i==2 && j==0) cout<<"Found\t\t";
              else if(i==3 && j==0) cout<<"Not Found\t";
              else if(i ==1 && j>0) cout<<a_d_b_time[j-1]<<"\t\t";
              else if(i==2 && j>0) cout<<a_d_s_find[j-1]<<"\t\t";
              else if(i==3 && j>0) cout<<a_d_u_find[j-1]<<"\t\t";
            }
            cout<<endl;
          }


      cout<<endl;
  }
  else if(choice == 3)
  {
    loop = false;
    cout<<"Byebye!\n";
  }
}



/*----------------------------------------------------------------*/
 // for(int i = 0; i<5; i++){
 //  cout<<h_b_time[i]<<" "<<q_b_time[i]<<" "<<d_b_time[i]<<endl;
 //  cout<<"Open Hash: "<<h_s_find[i]<<" "<<h_u_find[i]<<endl;
 //  cout<<"Quad Hash: "<<q_s_find[i]<<" "<<q_u_find[i]<<endl;
 //  cout<<"Doub Hash: "<<d_s_find[i]<<" "<<d_u_find[i]<<endl;
 // }

}
