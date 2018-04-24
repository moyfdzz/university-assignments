//
// Created by Moises Fernandez on 4/10/18.
//

#ifndef PROYECTO3_DISCO_H
#define PROYECTO3_DISCO_H

#include "Material.h"

class Disco : public Material
{
public:
    Disco();
    Disco(int, string, int);

    int getDuracion() { return duracion; }

    void setDuracion(int duracion) { this->duracion = duracion; }

    void muestra();
    int cantidadDeDiasDePrestamos();

private:
    int duracion;
};

Disco::Disco() : Material()
{
    duracion = 0;
}

Disco::Disco(int idM, string t, int duracion) : Material (idM, t)
{
    this->duracion = duracion;
}

void Disco::muestra()
{
    cout << "Tipo de material: Disco" << endl;
    cout << "Título: " << titulo << endl;
    cout << "Duración: " << duracion << endl;
    cout << "ID Disco: " << idMaterial << endl;
}

int Disco::cantidadDeDiasDePrestamos()
{
    return 3;
}

#endif //PROYECTO3_DISCO_H
