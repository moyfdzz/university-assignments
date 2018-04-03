#include <iostream>
using namespace std;

int main(){
	int xNumeros, numero, menor = 0;

  cin >> xNumeros;
	for (int i = 0; i < xNumeros; i++){
		cin >> numero;
		if (numero < menor)
			menor = numero;
	}
	cout << menor << endl;
}