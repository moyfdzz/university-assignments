#include <iostream>
using namespace std;

int main() {
  int renglones, columnas;

  cin >> renglones >> columnas;

  for (int cR = 0; cR < renglones; cR++){
    for (int cC = 0; cC < columnas; cC++){
      if (cR > 0 && cR < renglones - 1){
        if (cC > 0 && cC < columnas - 1){
          cout << " ";
        }
        else {
          cout << '*';
        }
      }
      else {
        cout << '*';
      }
    }
    cout << endl;
  }

  return 0;
}