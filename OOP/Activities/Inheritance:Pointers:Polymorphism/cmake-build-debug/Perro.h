//
// Created by Moises Fernandez on 3/23/18.
//

#ifndef ACTIVIDADANIMAL_PERRO_H
#define ACTIVIDADANIMAL_PERRO_H


#include "Animal.h"
class Perro: public Animal
{
public:
    Perro(string, int);
    void muestra();
    void habla();
};

Perro::Perro(string sNom, int iANac):Animal(sNom,iANac)
{

}

void Perro::muestra()
{
    cout << "Soy el perro " << sNombre << " y tengo ";
    cout << this->calculaEdad() << " años." << endl;
}

void Perro::habla()
{
    cout << "GUAU" << endl;
}


#endif //ACTIVIDADANIMAL_PERRO_H
