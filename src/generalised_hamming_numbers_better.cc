#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int M=1000000000;

const int priem[] = {
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int s;

void r(int n, long long k)
  {
  if(k > M) return;
  
  s++;
  
  for(int i=n;i<=24;i++) r(i,priem[i]*k);
  }
  

int main()
  {  
  double time=clock();
  
  s=0;
  
  r(0,1);
  
  cout<<s<<" in "<<clock()-time<<"ms"<<endl;  
  system("Pause"); return 0;
  }
