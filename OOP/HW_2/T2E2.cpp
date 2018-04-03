/*
@progName Justificar palabras
@desc Programa que justifica palabras hasta que tengan 25 caracteres
@author Moisés Fernández Zárate
@date 25 de enero del 2018 
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
@funcName countSpaces
@desc Cuenta los espacios de la frase
@param phrase frase o palabra que va a justificar y spaceCounter que son los números de espacios que tiene la palabra	
*/
//Función para contar los espacios
void countSpaces(string phrase, int &spaceCounter)
{
	for (int counter = 0; counter < phrase.length(); counter++)
	{
		if (phrase[counter] == ' ')
		{
			spaceCounter++;
		}
	}
}

/*
@funcName manageRemainingSpaces
@desc Es la función principal que agrega los espacios faltantes a la palabra para justificarla
@param phrase la frase o palabra que va a justificar, remainingSpaces que cuenta los espacios que faltan por agrega, spaceCounter el número de espacios y spaceDistribution que es cuántos espacios va a agregar entre palabra dentro de la frase
*/

//Función que maneja los espacios restantes para agregar los faltantes
void manageRemainingSpaces(string &phrase, int &remainingSpaces, int spaceCounter, 
													 int &spaceDistribution)
{
	int remainderSpaces;
	remainingSpaces = 25 - phrase.length();
	spaceDistribution = remainingSpaces / spaceCounter;
	remainderSpaces = remainingSpaces % spaceCounter;
	
	//Ciclos anidados para distribuir los espacios
	for (int counter = 0; counter < phrase.length(); counter++)
	{
		if (phrase[counter] == ' ')
		{
			for (int internalCounter = 0; internalCounter < spaceDistribution; internalCounter++)
			{
				phrase.insert(counter, " ");
				counter++;
			}
		}
	}
	
	//Más ciclos pero ahora para distribuir los espacios restantes (espacios a la derecha de la palabra o letra)
	for (int counter = phrase.length(); counter > 0 && remainderSpaces > 0; counter--)
	{
		if (phrase[counter] == ' ')
		{
			phrase.insert(counter, " ");
			remainderSpaces--;
			counter -= 2;
		}
	}
}

/*
@funcName main
@desc nombra todas las variables, llama a todas las funciones y agrega las palabras justificadas a otro archivo
*/

int main(){
	string phrase;
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("textoOriginal.txt");
	outputFile.open("textoModificado.txt");

	//Que siga leyendo mientras encuentre endl y llama a todas las funciones dependiendo del largo de las frases
	while (getline(inputFile, phrase))
	{
		int spaceCounter = 0, remainingSpaces = 0, spaceDistribution = 0;
		
		if (phrase.length() < 25)
		{
			countSpaces(phrase, spaceCounter);
			if (spaceCounter > 0)
			{
				manageRemainingSpaces(phrase, remainingSpaces, spaceCounter, spaceDistribution);
			}
		}
		outputFile << phrase << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}