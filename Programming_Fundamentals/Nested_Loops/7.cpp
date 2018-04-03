#include <iostream>
using namespace std;

int main() {
  int number;
  
  cin >> number;
  
  cout << "Pirámide" << endl;
  
  for (int i = 0; i < number; i++){
    for (int j = 0; j <= i; j++){
      cout << '*';
    }
    cout << endl;
  }
  cout << endl;
  
  cout << "Pirámide invertida" << endl;
  
  for (int i = 0; i < number; i++){
    for (int j = number; j > i; j--){
      cout << '*';
    }
    cout << endl;
  }
}