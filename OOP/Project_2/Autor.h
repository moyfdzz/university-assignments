//
// Created by Moises Fernandez on 3/3/18.
//

#ifndef PROYECTO2_AUTOR_H
#define PROYECTO2_AUTOR_H


class Autor
{
public:
    Autor();
    Autor(int, string);

    int getIdAutor() { return idAutor; }
    string getNombreAutor() { return nombreAutor; }

    void setIdAutor(int idAut) { idAutor = idAut; }
    void setNombreAutor(string nomAut) { nombreAutor = nomAut; }

private:
    int idAutor;
    string nombreAutor;
};

Autor::Autor()
{
    idAutor = 0;
    nombreAutor = "No asignado";
}

Autor::Autor(int idAutor, string nombreAutor)
{
    this->idAutor = idAutor;
    this->nombreAutor = nombreAutor;
}


#endif //PROYECTO2_AUTOR_H
