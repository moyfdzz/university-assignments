#include <iostream>
using namespace std;

void intercambia (char &x, char &y){
  char z;
  z = x;
  x = y;
  y = z;
}

int main() {
  int number;
  char ast = '*';
  char gato = '#';
  
  cin >> number;
  
  for (int i = 0; i < number; i++){
    for (int j = 0; j < number; j++){
      cout << ast;
      intercambia (ast, gato);
    }
    cout << endl;
  }
}