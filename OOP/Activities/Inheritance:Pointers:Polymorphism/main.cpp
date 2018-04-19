//Moisés Fernández Zárate A01197049

#include <iostream>
#include <string>
using namespace std;

#include "Gato.h"
#include "Perro.h"

int main()
{
  Animal *listaDeAnimales[3];
  listaDeAnimales[0] = new Gato("Silvestre",1947);
  listaDeAnimales[1] = new Perro("Fido",2000);
  listaDeAnimales[2] = new Gato("Tom",1940);

  for(int counter = 0; counter < 3;counter++)
  {
    listaDeAnimales[counter]->muestra();
    listaDeAnimales[counter]->habla();
  }

  return 0;
}