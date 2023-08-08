#include <cmath>
#include <iostream>
using namespace std;

bool ok(int q[], int c,
        int n) // c= current index of bishop ** n = size of the board
{
  for (int i = 0; i < c; i++) {
    if (abs(q[i] / n - q[c] / n) == abs((q[i] % n - q[c] % n)))
      return false;
  }
  return true;
}

int kbishops(int n, int k) // n= # of rows and cols
// k = # of bishops
{
  int *q = new int[n];
  q[0] = 0;
  int c = 0, solutions = 0;
  while (c >= 0) {
    c++;
    if (c == k) // if all bishops are placed
    {
      ++solutions;
      --c;
    } else
      q[c] = q[c - 1]; // set the position of the bishop to previous position
    while (c >= 0) {
      q[c]++;
      if (q[c] == n * n) // check if the current position of bishop exceeds the
                         // total number of squares on the board
        c--;             // backtrack
      else if (ok(q, c, n))
        break;
    }
  }
  delete[] q;
  return solutions;
}

int main() {
  int n, k;
  while (true) {
    cout << "Enter value of n: ";
    cin >> n;
    if (n == -1)
      break;
    cout << "Enter value of k: ";
    cin >> k;
    cout << "number of solutions: " << kbishops(n, k) << "\n";
  }
  return 0;
}