/*
Moisés Fernández Zárate A01197049
Tarea 1 Ejercicio 1
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Función que imprime los números del juego
void printPuzzle(int matrix[4][4]){
  for (int cRows = 0; cRows < 4; cRows++){
    for (int cColumns = 0; cColumns < 4; cColumns++){
      if (matrix[cRows][cColumns] == 0){
        cout << " ";
      }
      else
        cout << matrix[cRows][cColumns] << " ";
    }
    cout << endl;
  }
}

//Función para salir del juego
void exitGame(int userInput, bool &gameOn){
  if (userInput == 0){
      gameOn = 0;
    }
}

//Función para checar que el número del usuario sea correcto y si no, que lo vuelva a pedir
void correctInput(int matrix[4][4], int userInput){
  while (userInput < 0 || userInput > 15){
        printPuzzle(matrix);
        cin >> userInput;
      }
}

//Función para obtener la posición del número introducido por el usuario
void getPosInput(int matrix[4][4], int userInput, int &rowInput, int &columnInput){
    for (int cRows = 0; cRows < 4; cRows++){
        for (int cColumns = 0; cColumns < 4; cColumns++){
          if (matrix[cRows][cColumns] == userInput){
            rowInput = cRows;
            columnInput = cColumns;
          }
        }
      }
}

//Función para obtener la posición del cero (el espacio)
void getPosZero(int matrix[4][4], int userInput, int &rowZero, int &columnZero){
    for (int cRows = 0; cRows < 4; cRows++){
        for (int cColumns = 0; cColumns < 4; cColumns++){
          if (matrix[cRows][cColumns] == 0){
            rowZero = cRows;
            columnZero = cColumns;
          }
        }
      }
}

//Función para intercambiar con el espacio y el número introducido hacia arriba
void swapUp(int matrix[4][4], int userInput, int rowInput, int columnInput){
  matrix[rowInput - 1][columnInput] = userInput;
  matrix[rowInput][columnInput] = 0;
}

//Función para intercambiar con el espacio y el número introducido hacia abajo
void swapDown(int matrix[4][4], int userInput, int rowInput, int columnInput){
  matrix[rowInput + 1][columnInput] = userInput;
  matrix[rowInput][columnInput] = 0;
}

//Función para intercambiar con el espacio y el número introducido hacia los lados
void swapSides(int matrix[4][4], int userInput, int rowInput, int columnInput, int rowZero, int columnZero){
  if (matrix[rowInput][columnInput - 1] == 0 && rowInput == rowZero){
    matrix[rowInput][columnInput - 1] = userInput;
    matrix[rowInput][columnInput] = 0;
  }
  else if (matrix[rowInput][columnInput + 1] == 0 && rowInput == rowZero){
    matrix[rowInput][columnInput + 1] = userInput;
    matrix[rowInput][columnInput] = 0;
  }
}

//Función para intercambiar los dígitos
void swapDigits(int matrix[4][4], int userInput, int rowInput, int columnInput, int rowZero, int columnZero){
  for (int cRows = 0; cRows < 4; cRows++){
        for (int cColumns = 0; cColumns < 4; cColumns++){
          if (matrix[rowInput - 1][columnInput] == 0){ //Cambiar hacia arriba
            swapUp(matrix, userInput, rowInput, columnInput);
          }
          else if (matrix[rowInput + 1][columnInput] == 0){ //Cambiar hacia abajo
            swapDown(matrix, userInput, rowInput, columnInput);
          }
          else if (matrix[rowInput][columnInput - 1] == 0 || matrix[rowInput][columnInput + 1]== 0){ //Cambiar hacia los lados
            swapSides(matrix, userInput, rowInput, columnInput, rowZero, columnZero);
          }
        }
      }
}

//Función para ganar el juego
void winGame(int matrix[4][4], int winMatrix[4][4], bool &gameOn){
  if (matrix[4][4] == winMatrix[4][4]){
    printPuzzle(matrix);
    gameOn = 0;
  }
}

int main() {
  int matrix[4][4] = {4, 7, 2, 0, 3, 10, 1, 9, 5, 8, 12, 15, 6, 11, 13, 14};
  int winMatrix[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
  int userInput, rowInput, columnInput, rowZero, columnZero;
  bool gameOn = 1;
  
  do{
    printPuzzle(matrix);
  
    cin >> userInput;
  
    exitGame(userInput, gameOn);
      
    correctInput(matrix, userInput);
    
    getPosInput(matrix, userInput, rowInput, columnInput);
    
    getPosZero(matrix, userInput, rowZero, columnZero);
      
    swapDigits(matrix, userInput, rowInput, columnInput, rowZero, columnZero);
    
    winGame(matrix, winMatrix, gameOn);
  
  
  } while (gameOn);
  
  return 0;
}