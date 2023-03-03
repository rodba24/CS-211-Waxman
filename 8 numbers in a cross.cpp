#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int a[][5]){
  
  //row test
  for(int i=0;i<c; i++){
    if( q[i]== q[c] ) return false;
    }
  //adjacent test 
  int i = 0;
  while ( a[c][i]!= -1) {
    if(abs(q[a[c][i]]- q[c]) == 1) return false;
    i++;
  }
  return true;
}

void print (int q[], int solution){
  cout<< "solution # " << solution <<endl;                               //adding 1 to every cell because the answers will be from {0-7}
  cout<< "  " << q[0]+1 <<" " << q[1]+1 <<" "<<endl 
 << q[2]+1<< " "<< q[3]+1<< " "<< q[4] +1<< " "<< q[5] +1<< " "<<endl
   <<"  " << q[6] +1 << " " << q[7] +1 << " " <<endl; 
}
void backtrack (int &c){
  c--;
  if (c== -1) exit(0);
  }

int main(){
  int q[8]= {0};
  int c=0;   //column =0;
  int sol =0;
  //q[0]= 1; 
  
  int adj[8][5]= {          //to check if which cells q[c] is in conflict with 
{-1, 0, 0, 0, 0}, //0       //-1 represents you need to STOP
{0, -1, 0, 0, 0},//1
{0, -1, 0, 0, 0},//2
{0, 1, 2, -1, 0}, //3
{0, 1, 3, -1, 0},//4
{1, 4, -1, 0, 0},//5
{2, 3, 4, -1, 0},//6
{3, 4, 5, 6, -1}//7
    };

  while(c>=0){      //outer loop
    c++;
    if(c==8) print(q, sol++);
    
    q[c]=-1;
    
    while(c>=0){     //inner loop
      q[c]++;        
      if (q[c] == 8) backtrack(c);   //backtrack if q[c]=8
        
      else {
        if(ok(q, c, adj)) break;   //if there is no conflict go to the outer loop
       }    
      
    }
  }
  
}
