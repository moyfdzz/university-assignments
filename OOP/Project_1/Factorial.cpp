/**
@progName Factorial
@desc Programa que tiene una funcion para calcular el factorial de un numero
@author Yolanda Martinez
@date 28 de Enero de 2017
*/

#include <iostream>
using namespace std;

/**
@funcName factorial
@desc Calcula el factorial de un número
@param iNum valor para el que se va a calcular el factorial. Debe ser entero positivo.
@return factorial del valor iNum
*/

int factorial(int iNum)
{
	int iFac=1;

	// Calculate the factorial with a FOR loop
	for(int iC=1; iC<=iNum; iC++)
	{
		iFac = iFac*iC;
	}

	return iFac; // This value is returned to caller
}

/**
@funcName validaEntero
@desc Función que pide al usuario un valor y valida que sea entre 1 y 10
@return regresa el valor entero que tecleó el usuario (entre 1 y 10)
*/

int validaEntero()
{
	int iNum;

	do
	{
		cout << "Numero ";
		cin >> iNum;
	} while (iNum < 1 || iNum > 10);
	
	return iNum;
}

/**
@funcName main
@desc Pide el valor al usuario, calcula el factorial y lo muestra
*/

int main()
{
	int iNumero, iResult;
	iNumero = validaEntero();
	iResult = factorial(iNumero);
	cout << "Factorial = " << iResult << endl;
	return 0;
}