#include <iostream>
#include<cmath>
using namespace std;
int solution = 0;

  bool ok (int q[], int c)
  {
  for(int i = 0; i < c; i++)
  {
    if((q[i]==q[c]) || (c-i) == abs(q[i] - q[c])) //if there is a row or diagonal conflict return false
      return false;    
  }
    return true; 
  }

  void print (int q[])
  {
  solution++;  
  cout<< "Solution # " << solution<< ":" <<endl<<endl;
  for(int i = 0; i< 8; i++){
    for(int j=0; j<8; j++){
      if(i == q[j]) cout<< "1 "; //if (i) is equal to the value in q array [i in this case is the row ]
      else cout << "0 ";
    } 
    cout<<endl;
  }
  cout<<endl;
  }

  void backtrack (int &c)
  {
    c--;        // go back to previous column
    if(c == -1) exit(0);    
  }

  int main(){
    int q[8]={0};     //initialize board 
    int c = 0;        //   start on the first column
   
    while(c>=0)         //next col loop
    {     
      c++;     //next column
      if(c == 8) print(q);   // print the board
      q[c] = -1;  //row = -1
      
      while (c >=0)    //next row loop
      {
        q[c]++;  //go to next row
        
        if (q[c] == 8) backtrack(c);  //if row==8 backtrack 
          
        else 
        {
          if(ok (q, c)) break;  // call the ok function, if it returns true go back to the outer loop.
        }
      }
      
    }
    return 0;
  }
