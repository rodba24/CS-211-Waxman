#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> m;
  for (int i = 0; i < a.size(); i++) {
    m.push_back(a[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    m.push_back(b[i]);
  }
  return m;
}
void sort(vector<int> &v) {
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = 0; j < v.size() - 1; j++) {
      if (v[j] > v[j + 1]) {
        int temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
}

int main() {
  vector<int> a = {2, 3, 4, 5, 6};
  vector<int> b = {8, 9, 7, 1};
  vector<int> result = merge(a, b);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  sort(result);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
}
