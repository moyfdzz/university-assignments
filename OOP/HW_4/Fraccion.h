class Fraccion
{
	public:
		Fraccion();
		Fraccion(int, int);

		int getNum();
		int getDen();
		double calculaValorReal();
		
		void setNum(int);
		void setDen(int);

		void muestra();

	private:
		int num, den;
};

Fraccion :: Fraccion()
{
	num = 1;
  den = 1;
}

Fraccion :: Fraccion(int num, int den)
{
	this->num = num;
	this->den = den;
}

int Fraccion :: getNum()
{
	return num;
}

int Fraccion :: getDen()
{
	return den;
}

void Fraccion :: setNum(int num)
{
	this->num = num; 
}

void Fraccion :: setDen(int den)
{
	this->den = den; 
}

double Fraccion :: calculaValorReal()
{
	return (double) num/den;
}