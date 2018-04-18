//
// Created by Moises Fernandez on 4/10/18.
//

#ifndef PROYECTO3_MATERIAL_H
#define PROYECTO3_MATERIAL_H

class Material
{
public:
    Material();
    Material(int, string);

    int getIdMaterial() { return idMaterial; }
    string getTitulo() { return titulo; }

    void setIdMaterial(int idM) { idMaterial = idM; }
    void setTitulo(string t) { titulo = t; }

    virtual void muestra() = 0;
    virtual int cantidadDeDiasDePrestamos() = 0;

protected:
    int idMaterial;
    string titulo;
};

Material::Material()
{
    idMaterial = 0;
    titulo = "No asignado";
}

Material::Material(int idM, string t)
{
    idMaterial = idM;
    titulo = t;
}


#endif //PROYECTO3_MATERIAL_H
