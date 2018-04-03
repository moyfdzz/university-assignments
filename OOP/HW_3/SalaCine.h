#ifndef SalaCine_h
#define SalaCine_h

class SalaCine
{
	public:
			//constructor
    	SalaCine();

			//método de acceso
  		int getLugares();
  		string getPelicula();
  		
  		//método de modificación
    	void setLugares(int lugares);
    	void setPelicula(string pelicula);
    
    	//métodos
    	int compraBoleto(int);
    
	private:
			//atributos
    	int lugares;
    	string pelicula;
};

SalaCine :: SalaCine()
{
	lugares = 200;
	pelicula = "Harry Potter und der Stein der Weisen";
}

int SalaCine :: getLugares()
{
	return lugares;
}

string SalaCine :: getPelicula()
{
	return pelicula;
}

void SalaCine :: setLugares(int lug)
{
	lugares = lug;
}

void SalaCine :: setPelicula(string pel)
{
	pelicula = pel;
}

int SalaCine :: compraBoleto(int compraLugares)
{
	lugares -= compraLugares;
}

#endif /* SalaCine.h */