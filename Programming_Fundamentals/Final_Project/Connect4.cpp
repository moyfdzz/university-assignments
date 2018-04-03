/*
Creado por Moisés Fernández Zárate
Proyecto = Conecta 4
*/

#include <iostream>
#include <string>
using namespace std;

//Función para llenar la matriz
void fillBoard(int board[7][7]){
	for (int cLines = 0; cLines < 7; cLines++){
		for (int cColumns = 0; cColumns < 7; cColumns++){
			board[cLines][cColumns] = 0;
		}
	}
}

//Función para mostrar la matriz
void displayBoard(int board[7][7], char none, string &player, char player1, char player2){
	cout << "Es el turno del " << player << endl;
	cout << endl;
	cout << "    1   2   3   4   5   6   7" << endl;
	cout << "   ___________________________" << endl;
	for (int cLines = 0; cLines < 7; cLines++){
		cout << "  |   |   |   |   |   |   |   |" << endl;
		cout << cLines + 1 << " ";
		for (int cColumns = 0; cColumns < 7; cColumns ++){
			if (board[cLines][cColumns] == 0){
				cout << "| " << none << " ";
			}
			else if (board[cLines][cColumns] == 1){
				cout << "| " << player1 << " ";
			}
			else if (board[cLines][cColumns] == 2){
				cout << "| " << player2 << " ";
			}
		}
		cout << "|" << endl;
		cout << "  |___|___|___|___|___|___|___|" << endl;
	}
}

//Función que revisa que el número de columna introducido es válido
void validateColumnNumber (int &columnNumber, int board[7][7], char none, string &player, char player1, char player2){
	while (columnNumber < 1 || columnNumber > 7){
		displayBoard(board, none, player, player1, player2);
		cout << "Columna inválida. Por favor introduzca una columna válida (1 - 7)." << endl;
		cin >> columnNumber;
	}

	--columnNumber;
}

//Función que revisa si el espacio está vacío (que hay un "-")
void checkIfEmptySpace(bool &hasNotFoundSpace, int board[7][7], int &cLines, int columnNumber, int &playerTurn){
	while (hasNotFoundSpace){
		if (playerTurn % 2 == 0){
			if (board[cLines][columnNumber] == 0){
				board[cLines][columnNumber] = 1;
				hasNotFoundSpace = false;
			}
			else{
				--cLines;
			}
		}

		if (playerTurn % 2 != 0){
			if (board[cLines][columnNumber] == 0){
				board[cLines][columnNumber] = 2;
				hasNotFoundSpace = false;
			}
			else{
				--cLines;
			}
		}
	}

	playerTurn++;
	cLines = 6;
	hasNotFoundSpace = true;
}

//Función para preguntar si el usuario quiere seguir jugando
void continueGame(char &continuePlaying, bool &gameOn){
	cout << "¿Quieres seguir jugando? (s/n)" << endl;
	cin >> continuePlaying;

	while (continuePlaying != 's' && continuePlaying != 'S' && continuePlaying != 'n' && continuePlaying != 'N'){
		cout << "Respuesta inválida. Por favor introduzca una respuesta válida (s/n)." << endl;
		cin >> continuePlaying;
	}

	if (continuePlaying == 'n' || continuePlaying == 'N'){
		gameOn = false;
	}
}

//Función que revisa si ganó algún jugador horizontalmente
void winHorizontal(int board[7][7], int playerNumber, bool &gameOn, char none, string &player,
				   char player1, char player2){
	for (int cLines = 7; cLines > 0; cLines--){
		for (int cColumns = 0; cColumns < 7; cColumns++){
			if (board[cLines][cColumns] == playerNumber){
				if (board[cLines][cColumns + 1] == playerNumber){
					if (board[cLines][cColumns + 2] == playerNumber){
						if (board[cLines][cColumns + 3] == playerNumber){
							displayBoard(board, none, player, player1, player2);
							cout << "¡El Jugador " << playerNumber << " ganó horizontalmente!" << endl;
							gameOn = false;
							break;
						}
					}
				}
			}
		}
	}
}

//Función para revisar si hubo un empate
void draw(int board[7][7], int playerNumber, bool &gameOn, char none, string &player,
				 char player1, char player2){
	int cLines = 0;
	int cDifferent = 0;
	for (int cColumns = 0; cColumns < 7; cColumns++){
		if (board[cLines][cColumns] == playerNumber){
			cDifferent++;
		}
	}

	if (cDifferent == 7 && gameOn){
		displayBoard(board, none, player, player1, player2);
		cout << "¡Hubo un empate!" << endl;
		gameOn = false;
	}
}

//Función que revisa si ganó algún jugador verticalmente
void winVertical(int board[7][7], int playerNumber, bool &gameOn, char none, string &player,
			     char player1, char player2){
	for (int cLines = 7; cLines > 0; cLines--){
		for (int cColumns = 0; cColumns < 7; cColumns++){
			if (board[cLines][cColumns] == playerNumber){
				if (board[cLines + 1][cColumns] == playerNumber){
					if (board[cLines + 2][cColumns] == playerNumber){
						if (board[cLines + 3][cColumns] == playerNumber){
							displayBoard(board, none, player, player1, player2);
							cout << "¡El Jugador " << playerNumber << " ganó verticalmente!" << endl;
							gameOn = false;
							break;
						}
					}
				}
			}
		}
	}
}

//Función para checar si ganó algún jugador diagonalmente
void winDiagonal(int board[7][7], int playerNumber, bool &gameOn, char none, string &player,
				 char player1, char player2){
	for (int cLines = 7; cLines > 0; cLines--){
		for (int cColumns = 0; cColumns < 7; cColumns++){
			if (board[cLines][cColumns] == playerNumber){
				if (board[cLines - 1][cColumns + 1] == playerNumber){
					if (board[cLines - 2][cColumns + 2] == playerNumber){
						if (board[cLines - 3][cColumns + 3] == playerNumber){
							displayBoard(board, none, player, player1, player2);
							cout << "¡El Jugador " << playerNumber << " ganó diagonalmente!" << endl;
							gameOn = false;
							break;
						}
					}
				}
			}
			if (board[cLines][cColumns] == playerNumber){
				if (board[cLines - 1][cColumns - 1] == playerNumber){
					if (board[cLines - 2][cColumns - 2] == playerNumber){
						if (board[cLines - 3][cColumns - 3] == playerNumber){
							displayBoard(board, none, player, player1, player2);
							cout << "¡El Jugador " << playerNumber << " ganó diagonalmente!" << endl;
							gameOn = false;
							break;
						}
					}
				}
			}
		}
	}
}

//Función del sistema del juego que llama a todas las funciones anteriores para la funcionalidad del juego
void gameSystem(int board[7][7], char none, bool gameOn, bool &hasNotFoundSpace, string &player, char player1, char player2, 
				int &columnNumber, int &playerTurn, int &cLines, char &continuePlaying){
	while (gameOn){
		if (playerTurn % 2 == 0 && gameOn){
			player = "Jugador 1";
			displayBoard(board, none, player, player1, player2);
		
			if (playerTurn != 0){
				//continueGame(continuePlaying, gameOn);
			}

			if (!gameOn){
				break;
			}

			cout << "¿Qué columna quieres?" << endl;
			cin >> columnNumber;

			validateColumnNumber(columnNumber, board, none, player, player1, player2);

			checkIfEmptySpace(hasNotFoundSpace, board, cLines, columnNumber, playerTurn);

			winHorizontal(board, 1, gameOn, none, player, player1, player2);

			winVertical(board, 1, gameOn, none, player, player1, player2);

			winDiagonal(board, 1, gameOn, none, player, player1, player2);
		}

		if (playerTurn % 2 != 0 && gameOn){
			player = "Jugador 2";
			displayBoard(board, none, player, player1, player2);
		
			//continueGame(continuePlaying, gameOn);

			if (!gameOn){
				break;
			}

			cout << "¿Qué columna quieres?" << endl;
			cin >> columnNumber;

			validateColumnNumber(columnNumber, board, none, player, player1, player2);

			checkIfEmptySpace(hasNotFoundSpace, board, cLines, columnNumber, playerTurn);

			winHorizontal(board, 2, gameOn, none, player, player1, player2);

			winVertical(board, 2, gameOn, none, player, player1, player2);

			winDiagonal(board, 1, gameOn, none, player, player1, player2);
		}
	}
}

//Función principal que llama a todas las funciones de entrada, proceso y salida para poder jugar 
int main(){
	int board[7][7], columnNumber, playerTurn = 0, cLines = 6;
	char player1 ='X', player2 = 'O', none = '-', continuePlaying;
	bool gameOn = true, hasNotFoundSpace = true;
	string player = "Jugador 1";

	fillBoard(board);

	gameSystem(board, none, gameOn, hasNotFoundSpace, player, player1, player2, columnNumber, playerTurn, cLines, 
			   continuePlaying);

	return 0;
}