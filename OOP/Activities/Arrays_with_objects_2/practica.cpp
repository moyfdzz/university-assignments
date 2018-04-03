#include <iostream>
using namespace std;

#include "Complejo.h"

void llenarDatos(int &tam, Complejo listaComplejos[])
{
	cout << "¿Cuántos números quiere?" << endl;
	cin >> tam;

	listaComplejos[tam];

	for (int counter = 0; counter < tam; counter++)
	{
		cout << "Teclea los valores real e imaginario "<< endl;
		cin >> numeroReal >> numeroImaginario;
		listaComplejos[counter].setReal(numeroReal);
		listaComplejos[counter].setImag(numeroImaginario);
	}

	for (int counter = 0; counter < tam; counter++)
	{
		cout << counter << " :";
		listaComplejos[counter].muestra();
		cout << endl;
	}
}

void imprimirOpciones()
{
	cout << "Opciones" << endl;
	cout << "a. sumar 2 números" << endl;
	cout << "b. restar 2 números" << endl;
	cout << "c. sumar todos los números del arreglo" << endl;
	cout << "d. terminar" << endl;
}

void elegirOpcion(char opcion, int &subUno, int &subDos, Complejo resultado, Complejo listaComplejos[], int tam)
{
	cin > opcion;

	switch (opcion)
	{
		case 'a':
			cout << "Teclea los 2 subindices de los números a sumar" << endl;
			cin >> subUno >> subDos;

			resultado = listaComplejos[subUno].suma(listaComplejos[subDos]);

			cout << "Suma = " << resultado.muestra() << endl;

			break;
		case 'b';
			cout << "Teclea los 2 subindices de los números a sumar" << endl;
			cin >> subUno >> subDos;

			resultado = listaComplejos[subUno].resta(listaComplejos[subDos]);

			cout << "Resta = " << resultado.muestra() << endl;

			break;
		case 'c':
			resultado.setReal(0);
			resultado.setImag(0);
			for (int counter = 0; counter < tam; counter++)
			{
				resultado = resultado.suma(listaComplejos[counter]);
			}
			break;
	}
}

int main()
{
	int tam, numeroReal, numeroImaginario, subUno, subDos;
	char opcion;
	Complejo resultado, listaComplejos[tam];

	do
	{
		llenarDatos(tam, listaComplejos);
		imprimirOpciones();
		elegirOpcion(opcion, subUno, subDos,resultado, listaComplejos, tam);
	}while(opcion != 'd');
}