#include <iostream>
#include <math.h> 
using namespace std;

void exchange2Var (int &x, int &y){
  int z;
  z = x;
  x = y;
  y = z;
}

void exchange (int &a, int &b, int &c){
  int d;
    if (a > c || a == c){
      exchange2Var(a, c);
      if (a > b){
        exchange2Var(a, b);
      }
      else if (b > c){
        exchange2Var(b, c);
      }
    }
    else if (a < c){
      if (a > b){
        exchange2Var(a, b);
      }
      else if (b > c){
        exchange2Var(b, c);
      }
    }
    else if (a > b){
      exchange2Var(a, b);
      if (b > c){
        exchange2Var(b, c);
      }
    }
    
    
    cout << "El valor de a es = " << a << endl;
    cout << "El valor de b es = " << b << endl;
    cout << "El valor de c es = " << c << endl;
}

int main(){
    int a, b, c;
    
    cin >> a >> b >> c;
    
    exchange (a, b, c);
}