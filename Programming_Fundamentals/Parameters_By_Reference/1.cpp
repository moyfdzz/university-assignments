#include <iostream>
using namespace std;

void intercambia (double &a, double &b){
  double c;
  c = a;
  a = b;
  b = c;
}

int main(){
  double a, b;
  
  cin >> a >> b;
  
  cout << "Los valores son: x = " << a << " y = " << b << endl;
  
  intercambia (a, b);
  
  cout << "Intercambiados son: x = " << a << " y = " << b << endl;
}