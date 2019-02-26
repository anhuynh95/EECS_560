#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "HashTable.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
class Executive
{
public:
  Executive();
  void run();

private:
  int m = 1000003;
  int r = 100003;
  int k = 20;
  double h_b_time[5];
  double a_h_b_time[5];
  double q_b_time[5];
  double a_q_b_time[5];
  double d_b_time[5];
  double a_d_b_time[5];

  int h_s_find[5];
  double a_h_s_find[5];
  int h_u_find[5];
  double a_h_u_find[5];
  int q_s_find[5];
  double a_q_s_find[5];
  int q_u_find[5];
  double a_q_u_find[5];
  int d_s_find[5];
  double a_d_s_find[5];
  int d_u_find[5];
  double a_d_u_find[5];
};
#endif
