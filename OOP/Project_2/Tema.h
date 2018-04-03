//
// Created by Moises Fernandez on 3/3/18.
//

#ifndef PROYECTO2_TEMA_H
#define PROYECTO2_TEMA_H


class Tema
{
public:
    Tema();
    Tema(int, int, string);

    int getIdTema() { return idTema; }
    int getIdMateria() { return idMateria; }
    string getNombreTema() { return nombreTema; }

    void setIdTema(int idTem) { idTema = idTem; }
    void setIdMateria(int idMat) { idMateria = idMat; }
    void setNombreTema(string nomTema) { nombreTema = nomTema; }

private:
    int idTema, idMateria;
    string nombreTema;
};

Tema::Tema()
{
    idTema = 0;
    idMateria = 0;
    nombreTema = "No asignado";
}

Tema::Tema(int idTema, int idMateria, string nombreTema)
{
    this->idTema = idTema;
    this->idMateria = idMateria;
    this->nombreTema = nombreTema;
}


#endif //PROYECTO2_TEMA_H
