#include <iostream>
using namespace std;

int main(){
  int number;
  
  cin >> number;
  
  for (int i = 2; i <= number; i++){
    int result = 0;
    cout << "La tabla de multiplicar de " << i << endl;
    for (int j = 1; j <= 10; j++){
      result = i * j;
      cout << i << " X " << j << " = " << result << endl;
      result = 0;
    }
    cout << endl;
  }
}