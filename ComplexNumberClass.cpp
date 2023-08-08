#include <iostream>
using namespace std;

class complex {
private:
  int real;
  int imag;

public:
complex (int r, int i){
  real = r; 
  imag = i;
}
complex()
{
  real=0;// if you dont set them to 0 they will return weird number
  imag=0;
}
int getReal(){
  return real;
}
int getImag(){
  return imag;
}
void print(){
  cout<< real <<" + "<< imag<<endl;
}

complex operator +(complex c)
{
  complex temp;
  temp.real= real+ c.real;
  temp.imag = imag + c.imag;
  return temp;
}
complex operator -(complex c){
  complex temp;
  temp.real= real - c.real;
  temp.imag= imag - c.imag;
  return temp;
}
complex operator*(complex c){
  complex temp;
  temp.real= real*c.real- c.imag*imag;
  temp.imag= real*c.imag+ imag*c.real;
  return temp;
}
complex operator/(complex c){
  complex temp;
  temp.real= (real* c.real + imag* c.imag) /  (c.real * c.real + c.imag * c.imag);
  temp.imag= c.real* c.real+ c.imag * c.imag/  (c.real * c.real + c.imag * c.imag) ;
  return temp;
}

friend ostream& operator<<(ostream& os, complex c);
friend istream& operator>> (istream& is, complex& c);
};
ostream& operator<<(ostream& os, complex c){
  os<< c.real<<" + "<< c.imag<<"i"<<endl;
  return os;
}
istream& operator>>(istream& is, complex &c){
  is>> c.real>> c.imag;
  return is;
}

int main(){
  complex c1(5,4), c2(2,5), c3;
  c3= c1+c2;
  cout<< c1- c2<<endl;
  cout<< c1* c2<<endl;
  cout<< c1/c2<< endl;
  
  cout<< "c3 = "<< c3<< endl; //os operator

}

