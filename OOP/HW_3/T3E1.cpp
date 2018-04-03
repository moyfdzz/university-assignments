/*
Moisés Fernández Zárate A01197049
Tarea 3 Ejercicio 1
*/

#include <iostream>
#include <math.h>
using namespace std;

#include "Esfera.h"

int main() {
  Esfera objetoPrueba;
  double radio;
  
  cout << "El valor del radio default es: " << objetoPrueba.getRadio() << endl;
  cout << "El valor del área es: " << objetoPrueba.calcArea() << endl;
  cout << "El valor del volúmen es: " << objetoPrueba.calcVolum() << endl;
  
  cout << "Inserte un valor para el radio" << endl;
  cin >> radio;
  
  objetoPrueba.setRadio(radio);
  
  cout << "El valor del radio introducido es: " << objetoPrueba.getRadio() << endl;
  cout << "El valor del área con el nuevo radio es: " << objetoPrueba.calcArea() << endl;
  cout << "El valor del área con el nuevo radio es: " << objetoPrueba.calcVolum() << endl;
}