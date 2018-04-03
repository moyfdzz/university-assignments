//
// Created by Moises Fernandez on 3/2/18.
//

#ifndef PROYECTO2_FECHA_H
#define PROYECTO2_FECHA_H


class Fecha
{
public:
    Fecha();
    Fecha(int, int, int);

    int getDd() { return dd; }
    int getMm() { return mm; }
    int getAa() { return aa; }

    void setDd(int dd) { this->dd = dd; }
    void setMm(int mm) { this->mm = mm; }
    void setAa(int aa) { this->aa = aa; }

    void setFecha(int dd, int mm, int aa);

private:
    int dd, mm, aa;
};

Fecha::Fecha()
{
    dd = 1;
    mm = 1;
    aa = 2000;
}

Fecha::Fecha(int dd, int mm, int aa)
{
    this->dd = dd;
    this->mm = mm;
    this->aa = aa;
}

void Fecha::setFecha(int dd, int mm, int aa)
{
    this->dd = dd;
    this->mm = mm;
    this->aa = aa;
}


#endif //PROYECTO2_FECHA_H
