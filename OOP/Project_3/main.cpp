#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Reserva.h"

ifstream materiales("Material.txt");
ifstream reservas("Reserva.txt");
Material *arrGlobalMaterial[20];
Reserva arrGlobalReserva[50];
int cantMateriales = 0;
int cantReservaciones = 0;

void cargarDatosMateriales()
{
    int idMaterial, numPag, duracion;
    char clave;
    string titulo, autor, sistemaOper;

    while(materiales >> idMaterial >> titulo >> clave)
        switch(clave)
        {
            case 'L':
                materiales >> numPag >> autor;
                arrGlobalMaterial[cantMateriales++] = new Libro(idMaterial, titulo, numPag, autor);

                break;
            case 'D':
                materiales >> duracion;
                arrGlobalMaterial[cantMateriales++] = new Disco(idMaterial, titulo, duracion);

                break;
            case 'S':
                materiales >> sistemaOper;
                arrGlobalMaterial[cantMateriales++] = new Software(idMaterial, titulo, sistemaOper);

                break;
        }
}

void cargarDatosReservaciones()
{
    int dd, mm, aa, idMaterial, idCliente;

    while(reservas >> dd >> mm >> aa >> idMaterial >> idCliente)
    {
        Fecha f(dd, mm, aa);
        arrGlobalReserva[cantReservaciones].setFechaReservacion(f);
        arrGlobalReserva[cantReservaciones].setIdMaterial(idMaterial);
        arrGlobalReserva[cantReservaciones].setIdCliente(idCliente);
        cantReservaciones++;
    }
}

void cargarDatosArchivos()
{
    cargarDatosMateriales();
    cargarDatosReservaciones();
}

void consultarMateriales()
{
    for(int counter = 0; counter < cantMateriales; counter++)
    {
        arrGlobalMaterial[counter]->muestra();
        cout << endl;
    }
}

int infoPrestamo(int idMR, string &nM)
{
    for(int counter = 0; counter < cantMateriales; counter++)
    {
        int idMM = arrGlobalMaterial[counter]->getIdMaterial();
        if(idMR == idMM)
        {
            nM = arrGlobalMaterial[counter]->getTitulo();
            return arrGlobalMaterial[counter]->cantidadDeDiasDePrestamos();
        }
    }
}

void consultarReservaciones()
{
    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        Fecha fRI = arrGlobalReserva[counter].getFechaReservacion();

        cout << "Fecha de reservación inicio: " << fRI << endl;

        int idMR = arrGlobalReserva[counter].getIdMaterial();
        string nM;
        int cDP = infoPrestamo(idMR, nM);

        Fecha fRF = fRI + cDP;

        cout << "Fecha de reservación final: " << fRF << endl;
        cout << "Nombre de Material: " << nM << endl;
        cout << "ID de Cliente: " << arrGlobalReserva[counter].getIdCliente() << '\n' << endl;
    }
}

int infoPrestamoPorM(int idM, string &nM, Fecha &f)
{
    int cDP = 0;

    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        int idMR = arrGlobalReserva[counter].getIdMaterial();
        if(idM == idMR)
        {
            f = arrGlobalReserva[counter].getFechaReservacion();
            cDP = arrGlobalMaterial[counter]->cantidadDeDiasDePrestamos();
        }
    }

    for(int counter = 0; counter < cantMateriales; counter++)
    {
        int idMM = arrGlobalMaterial[counter]->getIdMaterial();
        if(idM == idMM)
        {
            nM = arrGlobalMaterial[counter]->getTitulo();
        }
    }

    return cDP;
}

bool encontrarMaterial(int idM)
{
    bool encontrar = true;

    for(int counter = 0; counter < cantMateriales; counter++)
    {
        if(idM == arrGlobalMaterial[counter]->getIdMaterial())
        {
            encontrar = true;
            break;
        }
        else
            encontrar = false;
    }

    return encontrar;
}

void consultarReservacionesDeMaterial()
{
    int idMaterial;
    cout << "Ingrese el ID del material: ";
    cin >> idMaterial;

    bool encontro = encontrarMaterial(idMaterial);

    while(!encontro)
    {
        cout << "El material no fue encontrado. Por favor intente con otro ID. " << endl;
        cin >> idMaterial;
        encontro = encontrarMaterial(idMaterial);
    }

    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        if(idMaterial == arrGlobalReserva[counter].getIdMaterial())
        {
            string nM;
            Fecha fRI = arrGlobalReserva[counter].getFechaReservacion();
            int cDP = infoPrestamoPorM(idMaterial, nM, fRI);
            Fecha fRF = fRI + cDP;

            cout << "Reservación número " << counter + 1 << endl;
            cout << "Nombre del material: " << nM << endl;
            cout << "Fecha de reservación inicial: " << fRI << endl;
            cout << "Fecha de reservación final: " << fRF << '\n' << endl;
        }
    }
}

void consultarReservacionesDeFecha()
{
    int dd, mm, aa, contador = 0;
    cout << "Ingrese la fecha (dd/mm/aa): ";
    cin >> dd >> mm >> aa;

    cout << endl;

    Fecha fU(dd, mm, aa);

    cout << "La lista de materiales reservados en la fecha " << fU << " es la siguiente:" << '\n' << endl;

    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        string nM;
        Fecha fRI = arrGlobalReserva[counter].getFechaReservacion();
        int idMaterial = arrGlobalReserva[counter].getIdMaterial();
        int cDP = infoPrestamoPorM(idMaterial, nM, fRI);
        Fecha fRF = fRI + cDP;
        if(fU == fRI || fU >= fRI && fU <= fRF)
        {
            contador++;
            cout << "Nombre del material: ";
            for(int counter2 = 0; counter2 < cantMateriales; counter2++)
            {
                    if(idMaterial == arrGlobalMaterial[counter2]->getIdMaterial())
                    {
                        cout << arrGlobalMaterial[counter2]->getTitulo();
                        break;
                    }
            }
            cout << '\n' << "ID del cliente: " << arrGlobalReserva[counter].getIdCliente() << '\n' << endl;
        }
    }

    if(contador == 0)
    {
        cout << "Ningún material está reservado en esa fecha." << endl;
    }
}

void hacerReservacion()
{
    int idCliente, idMaterial, dd, mm, aa;
    cout << "Ingrese su ID de cliente: ";
    cin >> idCliente;

    cout << "Ingrese el ID del material: ";
    cin >> idMaterial;

    bool encontro = encontrarMaterial(idMaterial);

    while(!encontro)
    {
        cout << "El material no fue encontrado. Por favor intente con otro ID. " << endl;
        cin >> idMaterial;
        encontro = encontrarMaterial(idMaterial);
    }

    cout << "Ingrese la fecha en la que quiere reservar el material (dd/mm/aa): ";
    cin >> dd >> mm >> aa;

    Fecha fU(dd, mm, aa);

    bool encuentraMaterial = true;

    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        string nM;
        Fecha fRI = arrGlobalReserva[counter].getFechaReservacion();
        int cDP = infoPrestamoPorM(idMaterial, nM, fRI);
        Fecha fRF = fRI + cDP;
        if(fU >= fRI && fU <= fRF)
        {
            encuentraMaterial = false;
            cout << "El material ya está reservado en la fecha " << fU << endl;
            break;
        }
    }

    if(!encuentraMaterial)
    {
        arrGlobalReserva[cantReservaciones].setFechaReservacion(fU);
        arrGlobalReserva[cantReservaciones].setIdMaterial(idMaterial);
        arrGlobalReserva[cantReservaciones].setIdCliente(idCliente);
        cantReservaciones++;
        cout << "Su reservación fue realizada con éxito. " << endl;
    }
}

void mostrarMenu()
{
    char opcion;

    do
    {
        cout << endl << "M E N U " << endl;
        cout << "a. consultar la lista de materiales" << endl;
        cout << "b. consultar la lista de reservas" << endl;
        cout << "c. consultar las reservaciones de un material dado" << endl;
        cout << "d. consultar las reservaciones de una fecha dada" << endl;
        cout << "e. hacer una reservación" << endl;
        cout << "f. terminar" << endl;
        cout << "Opcion -> ";
        cin >> opcion;

        switch (opcion)
        {
            case 'a':
                consultarMateriales();

                break;

            case 'b':
                consultarReservaciones();

                break;
            case 'c':
                consultarReservacionesDeMaterial();

                break;
            case 'd':
                consultarReservacionesDeFecha();

                break;
            case 'e':
                hacerReservacion();

                break;
        }
    } while (opcion != 'f');
}

int main()
{
    cargarDatosArchivos();

    mostrarMenu();

    materiales.close();
    reservas.close();

    return 0;
}