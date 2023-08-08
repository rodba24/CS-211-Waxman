#include <iostream>
using namespace std;

bool ok( int *q, int c){
  for(int i=0; i<c; i++){
    if(q[c]==q[i]|| abs(q[c]-q[i])== c-i) return false;
  }
  return true;
}

void print (int* q)
  {
  static int solution = 0;
  cout<< "Solution # " << ++solution<< ":" <<endl<<endl;
  for(int i = 0; i< 4; i++){
    for(int j=0; j< 4; j++){
      if(i == q[j]) cout<< "1 "; //if (i) is equal to the value in q array [i in this case is the row ]
      else cout << "0 ";
    } 
    cout<<endl;
  }
  cout<<endl;
  }

void move (int*q, int c){
  if (c == 4) {
    print(q);
    return;
  }
  for(int j =0; j <4; j++)
  {
    q[c]=j;
    if(ok(q,c)) 
      move(q, c+1);
  }
    
  }

int main(){
  int q[4];
  move(q,0);
  
}