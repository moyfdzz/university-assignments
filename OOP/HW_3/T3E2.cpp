/*
Moisés Fernández Zárate A01197049
Tarea 3 Ejercicio 2
*/

#include <iostream>
#include <string>
using namespace std;

#include "SalaCine.h"

int main() {
  SalaCine sala;
  int lugaresSala, compraLugares;
  char respuestaUsuario;
  bool seguirComprando = 1;
  string pelicula;
  
  cout << "¿Cuántos lugares tiene la sala?" << endl;
  cin >> lugaresSala;
  cout << "¿Cuál película presenta la sala?" << endl;
  cin.ignore();
  getline(cin, pelicula);
  
  sala.setLugares(lugaresSala);
  sala.setPelicula(pelicula);
  
  do
  {
    cout << "¿Cuántos boletos quiere comprar?" << endl;
    cin >> compraLugares;
  
    if (sala.getLugares() > compraLugares)
    {
      sala.compraBoleto(compraLugares);
    }
    else
      cout << "No hay suficientes lugares en la sala" << endl;
  
    cout << "Quedan " << sala.getLugares() << " lugares disponibles para la pelicula " << sala.getPelicula() << endl;
  
    cout << "¿Quiere seguir comprando boletos? (s/n) "<< endl;
    cin >> respuestaUsuario;
  
    if (respuestaUsuario == 'n'){
      seguirComprando = 0;
    }
  }while(seguirComprando);
  
}