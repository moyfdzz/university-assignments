//
// Created by Moises Fernandez on 3/3/18.
//

#ifndef PROYECTO2_MATERIA_H
#define PROYECTO2_MATERIA_H


class Materia
{
public:
    Materia();
    Materia(int, string);

    int getIdMateria() { return idMateria; }
    string getNombreMateria() { return nombreMateria; }

    void setIdMateria(int idMat) { idMateria = idMat; }
    void setNombreMateria(string nomMat) { nombreMateria = nomMat; }

private:
    int idMateria;
    string nombreMateria;
};

Materia::Materia()
{
    idMateria = 0;
    nombreMateria = "No asignado";
}

Materia::Materia(int idMateria, string nombreMateria)
{
    this->idMateria = idMateria;
    this->nombreMateria = nombreMateria;
}


#endif //PROYECTO2_MATERIA_H
