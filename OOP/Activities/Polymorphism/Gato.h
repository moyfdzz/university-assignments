//
// Created by Moises Fernandez on 3/23/18.
//

#ifndef ACTIVIDADANIMAL_GATO_H
#define ACTIVIDADANIMAL_GATO_H


#include "Animal.h"
class Gato: public Animal
{
public:
    Gato(string, int);
    void muestra();
    void habla();
};

Gato::Gato(string sNom, int iANac):Animal(sNom,iANac)
{
}

void Gato::muestra()
{
    cout << "Soy el gato " << sNombre << " y tengo ";
    cout << this->calculaEdad() << " años." << endl;
}

void Gato::habla()
{
    cout << "MIAU" << endl;
}


#endif //ACTIVIDADANIMAL_GATO_H
