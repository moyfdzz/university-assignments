#include <iostream>
using namespace std;

int main(){
	int numero;

	cout << "Ingrese el número" << endl;
	cin >> numero;

	while ((numero < 1) || (numero > 100)){
		cout << "Ingrese el número" << endl;
		cin >> numero;
	}
	
	cout << "El número es correcto" << endl;
}