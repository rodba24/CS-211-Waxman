#include <iostream>
#include<cstdlib>
using namespace std;

bool ascending(int i, int j){
  return i>j; // bc a[j]>a[j+1]
}
bool descending(int i, int j){
  return i<j;// bc a[j]<a[j+1]
}
typedef bool (*decide)(int, int); //makes an alias for ascending or descending takes 2 int returns a bool

void sort(int array[], int size, decide which){
  for(int i=0; i<size-1; i++){
    for(int j=0; j<size-1; j++){
      if(which(array[j], array[j+1])){
        int temp= array[j];
        array[j]= array[j+1];
        array[j+1]= temp;
      }
    }
  }
}


int main() {
int values[] = {40, 10, 100, 90, 20, 25};
sort(values, 6, descending);
  cout<< "desecending order: "<<endl;
  for (int n = 0; n < 6; n++) {
    cout << values[n] << " "<<endl;
  }
  sort(values, 6, ascending);
  cout<< "asecending order: "<<endl;
  for (int n = 0; n < 6; n++) {
    cout << values[n] << " ";
  }
  cout << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}