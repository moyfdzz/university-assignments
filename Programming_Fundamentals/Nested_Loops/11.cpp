#include <iostream>
using namespace std;

int main() {
  int number;
  
  cin >> number;
  
  for (int i = 0; i <= number; i++){
    for (int j = 1; j <= i; j++){
      cout << j;
    }
    cout << endl;
  }
  
  for (int i = number - 1; i != 0; i--){
    for (int j = 1; j <= i; j++){
      cout << j;
    }
    cout << endl;
  }
}