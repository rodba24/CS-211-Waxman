#include <cmath>
#include <iostream>
using namespace std;
int solution = 0;

bool ok(int q[], int c) {
  for (int i = 0; i < c; i++) {
    if ((q[i] == q[c]) ||
        (c - i) ==
            abs(q[i] -
                q[c])) // if there is a row or diagonal conflict return false
      return false;
  }
  return true;
}
int nqueens(int n) {
  int *q = new int[n]; // create an array to store the queens' positions
  q[0] = 0;            // place a queen
  int c = 0, solutions = 0;
  while (c >= 0) {
    c++;

    if (c == n) { // if all queens have been placed successfully
      ++solutions;
      c--; // backtrack to previous col
    } else
      q[c] = -1; // place the queen in the next col
    while (c >= 0) {
      q[c]++;
      if (q[c] == n) // if there are no more rows to try in the current column
        c--;         // backtrack
      else if (ok(q, c))
        break;
    }
  }
  delete[] q;       // deallocate memory for the array
  return solutions; // return #of sol
}
int main() {
  int n;
  cout << "Enter # of queens: ";
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cout << "There are " << nqueens(i) << " solutions to the " << i
         << " queens problem.\n";
  return 0;
}
