/*
Moisés Fernández Zárate A01197049
Tarea 2 Ejercicio 1
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	string idNumber; 
	int tests, individualTime;
	double times, average;
	ifstream archEnt;
	ofstream archSal;
	archEnt.open("tiempos.txt");
	archSal.open("promedios.txt");

	while (archEnt >> idNumber >> tests){
		average = 0;
		for (int counter = 0; counter < tests; counter++){
			archEnt >> individualTime;
			average += individualTime;
		}

		average /= tests;

		archSal << idNumber << "\t" << average << endl;
	}

	archEnt.close();
	archSal.close();

	return 0;
}