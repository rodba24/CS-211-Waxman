// Rat = rational numbers 
//performs rational number arithmetic 

#include <iostream>
using namespace std;

class Rat{
private:
int n; 
int d;

public:
Rat(){
  n=0;
  d=1;
}
//2 parameter
Rat(int i, int j){
  n=i;
  d=j;
}
//Conversion
Rat(int x){
  n=x;
  d=1;
}
int getN(){
  return n;
}
int getD(){
  return d;
}
void SetN(int x){
  n=x;
}
void SetD(int y){
  d=y;
}
//operator overloading
Rat operator+ (Rat r){  //returns rat takes rat as arguement x.operator+(y)
  Rat temp;
  temp.n= n*r.d+ d*r.n;
  temp.d= d*r.d;
  return temp;
}
Rat operator- (Rat r){
  Rat temp;
  temp.n= n*r.d-d*r.n;
  temp.d=d*r.d;
  return temp;
}
Rat operator*(Rat r){
  Rat temp; 
  temp.n= n*r.n;
  temp.d= d*r.d;
  return temp;
}
Rat operator/(Rat r){
  Rat temp;
  temp.n= n*r.d;
  temp.d= d*r.n;
  temp.reduce();
  return temp;
}
void reduce() {
        int gcdVal = gcd(n, d);
        n = n / gcdVal;
        d = d / gcdVal;
    }

int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
}
friend ostream& operator<<(ostream& os, Rat r);
friend istream& operator>>(istream& is, Rat& r);

};

ostream& operator<< (ostream& os, Rat r){
  os<< r.n <<"/"<<r.d<<endl;
  return os;
}
istream& operator>> (istream& is, Rat& r){
  is>> r.n>>r.d;
  return is;
}

int main(){
 Rat x(2,4), y(4,6), z;
 z=x/y;
 cout << "1/2 add 2/3: " << z << endl;
  
  x.SetN(3);
	y.SetD(2);
	z=x+y;
	cout <<"Set numerator to 3 of first and denominator to 2   of second and add 3/2 and 2/2: " << z << endl;
  cout << "Enter two integers:" << endl;
	
	cin >> x;
	cout << "Reduced: "<< x << endl;

	z= x+5;
	cout << "Add 5: " << z;

  return 0;

}























// // default constructor
// Rat()
// {  //FOR NUMBERS 0/1
//   n=0;
//   d=1;
// }
// // 2 parameter constructor
// Rat(int i, int j)
// {//assigns the input to n and d
//   n=i;
//   d=j;
// }
// // conversion constructor
// Rat(int i)
// {
//   n=i;
//   d=1;
// }
// //accessor functions
// int getNumerator()
// {
//   return n;
// }
// int getDemoniator()
// {
//   return d;
// }
// void setN(int i)
// {
//   n = i;
// }
// void setD(int i)
// {
//   d=i;
// }
// Rat operator+ (Rat r){
//   Rat t;
//   t.n = n*r.d+ d*r.n;
//   t.d = d*r.d;
//   return t;
// }
// friend ostream& operator<<(ostream& os, Rat r);
// friend istream& operator>>(istream& is, Rat& r);
// };

// ostream& operator<<(ostream& os, Rat r){
//   os<< r.n <<"/"<< r.d << endl;
//   return os;
// }
// istream& operator>>(istream& is, Rat& r){
//   is >> r.n >> r.d;
//   return is; 
// }


// int main() {
//    Rat r1(5, 2), r2(3, 2);
   
//    cout << "r1: " << r1 << endl;
//    cout << "r2: " << r2 << endl;
//    cout << "r1 + r2: " << r1 + r2 << endl;
// }
