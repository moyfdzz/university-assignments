#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Reserva.h"

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

        switch (opcion) {
            case 'a':


                break;

            case 'b':


                break;
            case 'c':


                break;
            case 'd':


                break;
            case 'e':


                break;
        }

    } while (opcion != 'f');
}

int main() {
    ifstream materiales("Material.txt");
    ifstream reservas("Reserva.txt");

    mostrarMenu();

    materiales.close();
    reservas.close();

    return 0;
}