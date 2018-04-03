#include <iostream>
using namespace std;

int main(){
	double xPrecio, xTotalArticulo;
	int xCantidad;
	char otroArticulo;

	int xArticulos = 0;
	double xTotal = 0;
	do{
		cout << "Precio del artículo ?" << endl;
		cin >> xPrecio;
		cout << "Cantidad a comprar ?" << endl;
		cin >> xCantidad;

		xTotalArticulo = xPrecio * xCantidad;

		xTotal += xTotalArticulo;
		xArticulos += xCantidad;

		cout << "El total de este artículo es $" << xTotalArticulo << endl;

		cout << "Desea comprar otro artículo ? (S/N)" << endl;
		cin >> otroArticulo;
	}
	while ((otroArticulo == 'S') ||  (otroArticulo == 's')); 

	cout << "Número de artículos comprados = " << xArticulos << endl;
	cout << "Total a pagar = " << xTotal << endl;

	return 0;
}