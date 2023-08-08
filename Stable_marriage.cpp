#include <iostream>
using namespace std;


bool ok(int q[], int c)
{
    static int mp[3][3] = {
        {0, 2, 1}, // Man 0 preferences
        {0, 2, 1}, // Man 1 preferences
        {1, 2, 0}, // Man 2 preferences
    };
    static int wp[3][3] = {
        {2, 1, 0}, // Women 0 preferences
        {0, 1, 2}, // Women 1 preferences
        {2, 0, 1}, // Women 2 preferences
    };

    int newMan = c, newWoman = q[c];

    for(int i = 0; i < c; i++) {
        int curMan = i, curWoman = q[i];

        if(newWoman == curWoman)
            return false;
        if(mp[curMan][newWoman] < mp[curMan][curWoman] && wp[newWoman][curMan] < wp[newWoman][newMan])
            return false;
        if(mp[newMan][curWoman] < mp[newMan][newWoman] && wp[curWoman][newMan] < wp[curWoman][curMan])
            return false;
    }
    return true;
}
  
void print(int q[])
{
    static int solution = 0;
    cout << "Solution #: " << ++solution << endl;
    cout << "Man   Women" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << "\t\t" << q[i] << endl;
        cout << endl;
    }
}
int main()
{
  int q[3]= {0};
  int c=0; 
  while(c>=0)
  {      //outer loop
  c++;
  if(c==3)  print(q);
 
  q[c]=-1;
    
  while(c>=0){     //inner loop
    q[c]++;        
    if (q[c] == 3) 
    {
      c--;
      if(c==-1) exit(0); 
   }
    else {
        if(ok(q, c)) break;   //if there is no conflict go to the outer loop
       }    
      
  }
  }
  }
