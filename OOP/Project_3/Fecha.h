//
// Created by Moises Fernandez on 4/10/18.
//

#ifndef PROYECTO3_FECHA_H
#define PROYECTO3_FECHA_H

#include "Reserva.h"
#include "Material.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

class Fecha
{
    // como friend la sobrecarga del operador >
    friend bool operator>(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador >=
    friend bool operator>=(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador <
    friend bool operator<(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador <=
    friend bool operator<=(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador ==
    friend bool operator==(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador +
    // que recibe como parametro una fecha y un numero entero
    // que representa una cantidad de dias y regresa
    // la fecha a la que se le agregaron los dias indicados
    friend Fecha operator+(Fecha f1, int dias);

    // como friend la sobrecarga del operador >>
    // que lee 3 valores enteros: dia, mes, anio con 4 digitos
    friend istream& operator>>(istream &is, Fecha &dato);

    // como friend la sobrecarga del operador <<
    // que muestra la fecha en el formato dd/mm/aaaa
    // no incluyas espacios ni enter
    friend ostream& operator<<(ostream &os, Fecha &dato);


public:
    Fecha() { dd = 0; mm = 0; aa = 0; }
    Fecha(int d, int m, int a) { dd = d; mm = m; aa = a; }
    int getDia() { return dd; }
    int getMes() { return mm; }
    int getAnio() { return aa; }
    void setFecha(int d, int m, int a) { dd = d; mm = m; aa = a; }
private:
    // atributos
    int dd, mm, aa;

    string nombreMes(int);
    bool esBisiesto();
};

string Fecha::nombreMes(int mm)
{
    switch(mm)
    {
        case 1:
            return "Ene";
        case 2:
            return "Feb";
        case 3:
            return "Mar";
        case 4:
            return "Abr";
        case 5:
            return "May";
        case 6:
            return "Jun";
        case 7:
            return "Jul";
        case 8:
            return "Ago";
        case 9:
            return "Sep";
        case 10:
            return "Oct";
        case 11:
            return "Nov";
        case 12:
            return "Dic";
        default:
            break;
    }
}

bool Fecha::esBisiesto()
{
    return (aa % 4 == 0 && aa % 100 != 0) || (aa % 400 == 0);
}

// como friend la sobrecarga del operador >
bool operator>(Fecha f1, Fecha f2)
{
    if(f1.aa > f2.aa)
    {
        return true;
    }
    else if(f1.aa == f2.aa)
    {
        if(f1.mm > f2.mm)
        {
            return true;
        }
        else if(f1.mm == f2.mm)
        {
            return f1.dd > f2.dd;
        }
        else
            return false;
    }
    else
        return false;
}

// como friend la sobrecarga del operador >=
bool operator>=(Fecha f1, Fecha f2)
{
    return(f1 > f2 || f1 == f2);
}

// como friend la sobrecarga del operador <
bool operator<(Fecha f1, Fecha f2)
{
    return(!(f1>=f2));
}

// como friend la sobrecarga del operador <=
bool operator<=(Fecha f1, Fecha f2)
{
    return(f1 < f2 || f1 == f2);
}

// como friend la sobrecarga del operador ==
bool operator==(Fecha f1, Fecha f2)
{
    return(f1.aa == f2.aa && f1.mm == f2.mm && f1.dd == f2.dd);
}

// como friend la sobrecarga del operador +
// que recibe como parametro una fecha y un numero entero
// que representa una cantidad de dias y regresa
// la fecha a la que se le agregaron los dias indicados
Fecha operator+(Fecha f1, int dias)
{
    int diasSumados = f1.dd + dias;

    switch(f1.mm)
    {
        //Meses con 31 días
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(diasSumados < 32)
            {
                f1.dd = diasSumados;
            }
            else if(diasSumados >= 32)
            {
                f1.dd = diasSumados - 31;
                f1.mm++;
            }

            return f1;

            //31 días pero cambio de año
        case 12:
            if(diasSumados < 32)
            {
                f1.dd = diasSumados;
            }
            else if(diasSumados >= 32)
            {
                f1.dd = diasSumados - 31;
                f1.mm = 1;
                f1.aa++;
            }

            return f1;

            //28 o 29 días, dependiendo de si es bisiesto
        case 2:
            if(f1.esBisiesto())
            {
                if(diasSumados < 30)
                {
                    f1.dd = diasSumados;
                }
                else if(diasSumados >= 30)
                {
                    f1.dd = diasSumados - 29;
                    f1.mm++;
                }
            }
            else {
                if(diasSumados < 29)
                {
                    f1.dd = diasSumados;
                }
                else if(diasSumados >= 29)
                {
                    f1.dd = diasSumados - 28;
                    f1.mm++;
                }
            }

            return f1;

            //Meses con 30 días
        case 4:
        case 6:
        case 9:
        case 11:
            if(diasSumados < 31)
            {
                f1.dd = diasSumados;
            }
            else if(diasSumados >= 31)
            {
                f1.dd = diasSumados - 30;
                f1.mm++;
            }

            return f1;
    }
}

// como friend la sobrecarga del operador >>
// que lee 3 valores enteros: dia, mes, anio con 4 digitos
istream& operator>>(istream &is, Fecha &dato)
{
    is >> dato.dd >> dato.mm >> dato.aa;

    return is;
}

// como friend la sobrecarga del operador <<
// que muestra la fecha en el formato dd/mm/aaaa
// no incluyas espacios ni enter
ostream& operator<<(ostream &os, Fecha &dato)
{
    os << dato.dd << "/" << dato.nombreMes(dato.mm) << "/" << dato.aa;

    return os;
}

#endif //PROYECTO3_FECHA_H
