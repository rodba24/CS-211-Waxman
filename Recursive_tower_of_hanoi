#include<iostream>
using namespace std;

void move(char f, char t, char e, int n) {

  if (n==1) {
    cout<< "Transfer Tower "<<f<<" to "<< "Tower "<< t<< endl;
  return;
  }
move(f, e, t, n-1);
cout<< "transfer ring from "<< f<< " to " << e<<endl;
  
move(e, t, f, n-1);
}

int main()
{
  int n;
  cout<< "enter: ";
  cin>> n;
  
  move('A', 'B', 'C', n);
  
  return 0;
}
