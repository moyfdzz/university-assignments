#ifndef Esfera_h
#define Esfera_h

class Esfera 
{
	public:
			//constructor
    	Esfera();

			//método de acceso
  		double getRadio();
  		
  		//método de modificación
    	void setRadio(double radio);
    
    	//métodos
    	double calcArea();
  		double calcVolum();
    
	private:
			//atributo
    	double radio;
};

Esfera :: Esfera()
{
	radio = 1;
}

double Esfera :: getRadio()
{
	return radio;
}

void Esfera :: setRadio(double rad)
{
	radio = rad;
}

double Esfera :: calcArea()
{
	return 4 * 3.1416 * pow(radio, 2);
}

double Esfera :: calcVolum()
{
	return (4 * 3.1416 * pow(radio, 3)) / 3;
}

#endif /* Esfera.h */