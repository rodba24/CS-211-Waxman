#include <iostream>
using namespace std;

int fib(int n){
  static int memo[100]={0};
  if(n==1||n==2) return 1;
  if(memo[n]>0) return memo[n];
  return memo[n]= fib(n-1)+ fib(n-2);
}

int fact(int n){
  static int memo[100]={0};
  if(n==0||n==1) return 1;
  if(memo[n]>0) return memo[n];
  return memo[n]= n*fact(n-1);
}

int main(){
  int n=8;
  cout<< fact(n)<<endl;
  cout<< fib(n);
}


