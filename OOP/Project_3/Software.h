//
// Created by Moises Fernandez on 4/10/18.
//

#ifndef PROYECTO3_SOFTWARE_H
#define PROYECTO3_SOFTWARE_H

#include "Material.h"

class Software : public Material
{
public:
    Software();
    Software(int, string, string);

    string getSistemaOper() { return sistemaOper; }

    void setSistemaOper(string sO) { sistemaOper = sO; }

    void muestra();
    int cantidadDeDiasDePrestamos() override;

private:
    string sistemaOper;
};

Software::Software() : Material()
{
    sistemaOper = "No asignado";
}

Software::Software(int idM, string t, string sO) : Material(idM, t)
{
    sistemaOper = sO;
}

void Software::muestra()
{
    cout << "Tipo de material: Software" << endl;
    cout << "Título: " << titulo << endl;
    cout << "Sistema operativo: " << sistemaOper << endl;
    cout << "ID Software: " << idMaterial << endl;
}

int Software::cantidadDeDiasDePrestamos()
{
    return 1;
}

#endif //PROYECTO3_SOFTWARE_H
