//
// Created by Moises Fernandez on 4/10/18.
//

#ifndef PROYECTO3_LIBRO_H
#define PROYECTO3_LIBRO_H

#include "Material.h"

class Libro : public Material
{
public:
    Libro();
    Libro(int, string, int, string);

    int getNumPag() { return numPag; }
    string getAutor() { return autor; }

    void setNumPag(int numPag) { this->numPag = numPag; }
    void setAutor(string autor) { this->autor = autor; }

    void muestra();
    int cantidadDeDiasDePrestamo();

private:
    int numPag;
    string autor;
};

Libro::Libro() : Material()
{
    numPag = 0;
    autor = "No asignado";
}

Libro::Libro(int idM, string t, int numPag, string autor) : Material (idM, t)
{
    this->numPag = numPag;
    this->autor = autor;
}

void Libro::muestra()
{
    cout << "Tipo de material: Libro" << endl;
    cout << "Título: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Número de páginas: " << numPag << endl;
    cout << "ID Libro: " << idMaterial << endl;
}

int Libro::cantidadDeDiasDePrestamo()
{
    return 10;
}

#endif //PROYECTO3_LIBRO_H
