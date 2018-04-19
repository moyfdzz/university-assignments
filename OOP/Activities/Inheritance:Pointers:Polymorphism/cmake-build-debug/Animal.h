//
// Created by Moises Fernandez on 3/23/18.
//

#ifndef ACTIVIDADANIMAL_ANIMAL_H
#define ACTIVIDADANIMAL_ANIMAL_H


class  Animal
{
public:
    Animal(string,  int);
    int  calculaEdad();
    virtual  void  habla()  =  0; //Nota  que  son  funciones  virtual  pura.
    virtual  void  muestra()  =  0; //  ENTONCES  la  clase  es  abstracta.
protected:
    string  sNombre;
    int  iAnioNacim;
};
Animal::Animal(string  sNom,  int  iANac)
{
    sNombre  =  sNom;
    iAnioNacim  =  iANac;
}
int  Animal::calculaEdad()
{
    return  2015 - iAnioNacim;
}


#endif //ACTIVIDADANIMAL_ANIMAL_H
