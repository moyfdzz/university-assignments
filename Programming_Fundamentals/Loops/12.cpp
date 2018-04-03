#include <iostream>
using namespace std;

int main(){
	char clave, otro;
	int precio = 0, suma = 0;

	cout << "Ingrese la clave del artículo ";
	cin >> clave;

	if (clave == 'A'){
		precio = 120;
	}
	else if (clave == 'B'){
		precio = 250;
	}
	else if (clave == 'C'){
		precio = 300;
	}

	cout << precio << endl;
	suma += precio;

	cout << "¿Quiere otro producto? ";
	cin >> otro;

	while (otro == 's'){
		cout << "Ingrese la clave del artículo";
		cin >> clave;
		if (clave == 'A'){
		precio = 120;
		}
	else if (clave == 'B'){
		precio = 250;
		}
	else if (clave == 'C'){
		precio = 300;
		}
		cout << precio << endl;
		suma += precio;
		cout << "Quiere otro producto? ";
		cin >> otro;
	}

  if (otro == 'n'){
	  cout << "El total es " << suma << endl;
  }
}
