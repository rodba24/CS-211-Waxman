#include <iostream>
using namespace std;
 int memo[7][7] = {0};
int path(int r, int c) {
  if (r == 5 || c == 0) //OR YOU CAN CHANGE THE ZEROS TO 1S
    return 1;
  if (memo[r][c] > 0)
    return memo[r][c];
  return memo[r][c] = path(r, c - 1) + path(r + 1, c);
}

int main() 
{ 
 
  cout<< path(0,5); // 0,5 is where the food is
}
