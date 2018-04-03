/*
Moisés Fernández Zárate A01197049
Tarea 1 Ejercicio 2
*/

#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Función que tira los dos dados y los suma
void throwDices(int &firstDice, int &secondDice, int &data, int array[]){
	for (int cThrows = 0; cThrows < 200; cThrows++){
		firstDice = 1 + rand() % 6;
		secondDice = 1 + rand() % 6;
		data = firstDice + secondDice;
		array[data] += 1;
	}
}

//Función que va a imprimir un histograma accesando a los datos del array con ciclos anidados
void printHistogram(int array[]){
	for (int counter = 2; counter < 13; counter++){
		if(counter <= 9){
			cout << counter << "  | ";
		}
		else if(counter > 9){
			cout << counter << " | ";
		}
		
		//Ciclo para imprimir los asteriscos del histograma
		for (int cAsterisk = 0; cAsterisk < array[counter]){
			cout << '*';
		}
		
		cout << endl;
		
	}
}

//Función que calcula los valores que mayor y menor probabilidad de salir
void probabilityCalculation(int array[]){
	int highestProb, lowestProb;
	
	//Ciclo para sacar el número con menor probabilidad
  for(int counter = 2; counter < 13; counter++){
  	if(array[1] > array[counter]){
        array[1] = array[counter];
      	lowestProb = counter;
    }
  }
	
	//Ciclo para sacar el número con mayor probabilidad
	for(int counter = 2; counter < 13; counter++){
		if(array[0] < array[counter]){
      array[0] = array[counter];
      highestProb = counter;
    }
	}
	
	cout << "El valor que tiene más probabilidad de salir es: " << highestProb << endl;
	cout << "El valor que tiene menos probabilidad de salir es: " << lowestProb << endl;
	
}

int main() {
  int firstDice, secondDice, data;
  int array[13];
  
  srand(time(0));

	throwDices(firstDice, secondDice, data, array);
  
  printHistogram(array);
  
  probabilityCalculation(array);
  
}