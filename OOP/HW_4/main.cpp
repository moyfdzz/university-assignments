#include <iostream>
#include <math.h>
using namespace std;

#include "Termino.h"

void llenarTerminosPolinomio(int numTerminos, int numCoef, 
														 int denCoef, Fraccion coeficiente,
														 Termino polinomioTerminos[],
														 int exponente)
{
	for(int counter = 0; counter < numTerminos; counter++)
  {
  	cout << "Teclea el numerador del coeficiente del término " << counter << endl;
  	cin >> numCoef;
  	coeficiente.setNum(numCoef);
  	
  	cout << "Teclea el denominador del coeficiente del término " << counter << endl;
  	cin >> denCoef;
  	coeficiente.setDen(denCoef);
  	
  	polinomioTerminos[counter].setCoeficiente(coeficiente);
  	
  	cout << "Teclea el exponente del término " << counter << endl;
  	cin >> exponente;
  	
  	if(exponente <= 0)
  	{
  		exponente = 1;
  	}
  	
  	polinomioTerminos[counter].setExponente(exponente);
  }
}

void imprimirPolinomio(Termino polinomioTerminos[], int numTerminos)
{
	cout << "Su polinomio es:";
  
  for(int counter = 0; counter < numTerminos; counter++)
  {
  	polinomioTerminos[counter].muestra();
  }
  
  cout << endl;
}

void evaluarPolinomio(int numTerminos, int numCoef, 
														 int denCoef, Fraccion coeficiente,
														 Termino polinomioTerminos[],
														 int exponente, double &valorPolinomio, 
														 int valorVariable)
{
	for(int counter = 0; counter < numTerminos; counter++)
	{
		double numC = polinomioTerminos[counter].getCoeficiente().getNum();
		double denC = polinomioTerminos[counter].getCoeficiente().getDen();
		double valorCoeficiente = numC / denC;
		double valorExponente = polinomioTerminos[counter].getExponente();
		double valorVarAlExponente = pow(valorVariable, valorExponente);
		valorPolinomio += valorCoeficiente * valorVarAlExponente;
	}
}

int main() 
{
	int exponente, numCoef, denCoef, numTerminos, valorVariable;
	double valorPolinomio = 0;
	char variable;
  Fraccion coeficiente;
  
  cout << "¿Cuántos terminos tiene el polinomio?" << endl;
  cin >> numTerminos;
  Termino polinomioTerminos[numTerminos];
  
  cout << "¿Cuál es la letra para la variable del polinomio?" << endl;
  cin >> variable;
  
  llenarTerminosPolinomio(numTerminos, numCoef, denCoef, coeficiente, 
  												polinomioTerminos, exponente);
  imprimirPolinomio(polinomioTerminos, numTerminos);
  
  cout << "Para evaluar el polinomio, teclea el valor de la variable" << endl;
  cin >> valorVariable;
  
  evaluarPolinomio(numTerminos, numCoef, denCoef, coeficiente, 
  								 polinomioTerminos, exponente, valorPolinomio,
  								 valorVariable);
  
  cout << "El valor del polinomio es: " << valorPolinomio << endl;
  
  return 0;
}