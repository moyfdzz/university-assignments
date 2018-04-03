#include "Fraccion.h"

class Termino
{
	public:
		Termino();
		Termino(Fraccion, char, int);
		
		Fraccion getCoeficiente();
		char getVariable();
		int getExponente();
		
		void setCoeficiente(Fraccion);
		void setVariable(char);
		void setExponente(int);
		
		void muestra();
		
	private:
		Fraccion coeficiente;
		char variable;
		int exponente;
};

Termino :: Termino()
{
	coeficiente.setNum(1);
	coeficiente.setDen(1);
	variable = 'x';
	exponente = 1;
}

Termino :: Termino(Fraccion coeficiente, char variable, int exponente)
{
	this->coeficiente = coeficiente;
	this->variable = variable;
	this->exponente = exponente;
}

Fraccion Termino :: getCoeficiente()
{
	return coeficiente;
}

char Termino :: getVariable()
{
	return variable;
}

int Termino :: getExponente()
{
	return exponente;
}

void Termino :: setCoeficiente(Fraccion coeficiente)
{
	this->coeficiente = coeficiente;
}

void Termino :: setVariable(char variable)
{
	this->variable = variable;
}

void Termino :: setExponente(int exponente)
{
	this->exponente = exponente;
}

void Termino :: muestra()
{
	if(coeficiente.getNum() > 0 && coeficiente.getDen() > 0)
	{
		cout << " + ";
	}
	else
	{
		cout << " ";
	}
	
	if(coeficiente.getNum() > 0 && coeficiente.getDen() < 0 || coeficiente.getNum() < 0 && coeficiente.getDen() < 0)
	{
		cout << coeficiente.getNum() - coeficiente.getNum() * 2 << "/";
		cout << coeficiente.getDen() + coeficiente.getDen() * (-2);
		cout << variable;
	}
	else
	{
		cout << coeficiente.getNum() << "/";
		cout << coeficiente.getDen() << variable;
	}
	
	if (getExponente() != 1)
	{
		cout << '^' << getExponente();
	}
}