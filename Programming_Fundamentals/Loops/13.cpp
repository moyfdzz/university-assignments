#include <iostream>
using namespace std;

int main(){
	int xNumeros, numero, mayor = 0;

  cin >> xNumeros;
	for (int i = 0; i < xNumeros; i++){
		cin >> numero;
		if (numero > mayor)
			mayor = numero;
	}
	cout << mayor << endl;
}