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
        Fecha fechaReservacion(dd, mm, aa);
        arrGlobalReserva[cantReservaciones].setFechaReservacion(fechaReservacion);
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

int infoPrestamo(int idMaterialReservaciones, string &nombreMaterial)
{
    for(int counter = 0; counter < cantMateriales; counter++)
    {
        int idMaterialMateriales = arrGlobalMaterial[counter]->getIdMaterial();
        if(idMaterialReservaciones == idMaterialMateriales)
        {
            nombreMaterial = arrGlobalMaterial[counter]->getTitulo();
            return arrGlobalMaterial[counter]->cantidadDeDiasDePrestamos();
        }
    }
}

void consultarReservaciones()
{
    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        Fecha fechaReservacionInicial = arrGlobalReserva[counter].getFechaReservacion();

        cout << "Fecha de reservación inicio: " << fechaReservacionInicial << endl;

        int idMaterialReservas = arrGlobalReserva[counter].getIdMaterial();
        string nombreMaterial;
        int cantDiasPrestamo = infoPrestamo(idMaterialReservas, nombreMaterial);

        Fecha fechaReservacionFinal = fechaReservacionInicial + cantDiasPrestamo;

        cout << "Fecha de reservación final: " << fechaReservacionFinal << endl;
        cout << "Nombre de Material: " << nombreMaterial << endl;
        cout << "ID de Cliente: " << arrGlobalReserva[counter].getIdCliente() << '\n' << endl;
    }
}

int infoPrestamoPorM(int idMaterial, string &nombreMaterial, Fecha &fechaReservacion)
{
    int cantDiasPrestamo = 0;

    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        int idMaterialReservaciones = arrGlobalReserva[counter].getIdMaterial();
        if(idMaterial == idMaterialReservaciones)
        {
            fechaReservacion = arrGlobalReserva[counter].getFechaReservacion();
            cantDiasPrestamo = arrGlobalMaterial[counter]->cantidadDeDiasDePrestamos();
        }
    }

    for(int counter = 0; counter < cantMateriales; counter++)
    {
        int idMaterialMateriales = arrGlobalMaterial[counter]->getIdMaterial();
        if(idMaterial == idMaterialMateriales)
        {
            nombreMaterial = arrGlobalMaterial[counter]->getTitulo();
        }
    }

    return cantDiasPrestamo;
}

bool encontrarMaterial(int idMaterial)
{
    bool encontrar = false;

    for(int counter = 0; counter < cantMateriales; counter++)
    {
        if(idMaterial == arrGlobalMaterial[counter]->getIdMaterial())
        {
            encontrar = true;
        }
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
            string nombreMaterial;
            Fecha fechaReservacionInicial = arrGlobalReserva[counter].getFechaReservacion();
            int cantDiasPrestamo = infoPrestamoPorM(idMaterial, nombreMaterial, fechaReservacionInicial);
            Fecha fechaReservacionFinal = fechaReservacionInicial + cantDiasPrestamo;

            cout << "Reservación número " << counter + 1 << endl;
            cout << "Nombre del material: " << nombreMaterial << endl;
            cout << "Fecha de reservación inicial: " << fechaReservacionInicial << endl;
            cout << "Fecha de reservación final: " << fechaReservacionFinal << '\n' << endl;
        }
    }
}

void consultarReservacionesDeFecha()
{
    int dd, mm, aa, contador = 0;
    cout << "Ingrese la fecha (dd/mm/aa): ";
    cin >> dd >> mm >> aa;

    cout << endl;

    Fecha fechaUsuario(dd, mm, aa);

    cout << "La lista de materiales reservados en la fecha " << fechaUsuario << " es la siguiente:" << '\n' << endl;

    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        string nombreMaterial;
        Fecha fechaReservacionInicial = arrGlobalReserva[counter].getFechaReservacion();
        int idMaterial = arrGlobalReserva[counter].getIdMaterial();
        int cantDiasPrestamo = infoPrestamoPorM(idMaterial, nombreMaterial, fechaReservacionInicial);
        Fecha fechaReservacionFinal = fechaReservacionInicial + cantDiasPrestamo;
        if(fechaUsuario == fechaReservacionInicial || fechaUsuario >= fechaReservacionInicial && fechaUsuario <= fechaReservacionFinal)
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

    Fecha fechaUsuario(dd, mm, aa);

    bool encuentraMaterial = true;

    for(int counter = 0; counter < cantReservaciones; counter++)
    {
        string nombreMaterial;
        Fecha fechaReservacionInicial = arrGlobalReserva[counter].getFechaReservacion();
        int cantDiasPrestamo = infoPrestamoPorM(idMaterial, nombreMaterial, fechaReservacionInicial);
        Fecha fechaReservacionFinal = fechaReservacionInicial + cantDiasPrestamo;
        if(fechaUsuario >= fechaReservacionInicial && fechaUsuario <= fechaReservacionFinal)
        {
            encuentraMaterial = false;
            cout << "El material ya está reservado en la fecha " << fechaUsuario << endl;
            break;
        }
    }

    if(!encuentraMaterial)
    {
        arrGlobalReserva[cantReservaciones].setFechaReservacion(fechaUsuario);
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