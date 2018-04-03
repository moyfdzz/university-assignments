#include <iostream>
using namespace std;

int main(){
	int iTests, numero, xPar = 0, xImp = 0;

	cout << "Numero?" << endl;
	cin >> iTests;

	for (int i = 0; i < iTests; i++){
		cin >> numero;
		if (numero % 2 == 0){
			cout << "es par" << endl;
			xPar++;
		}
		if (numero % 2 != 0){
			cout << "es impar" << endl;
			xImp++;
		}
	}
	cout << "La cantidad de pares es = " << xPar << endl;
	cout << "La cantidad de impares es = " << xImp << endl;
}