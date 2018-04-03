#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string phrase, firstLetters;

	cout << "Introduzque la frase" << endl;
	getline(cin, phrase);

	firstLetters += phrase[0];

	for (int counter = 0; counter <= phrase.length() - 1; counter++)
	{
		if (phrase[counter] == ' ' && phrase[counter + 1] != ' ')
		{
			firstLetters += phrase[counter + 1];
		}
	}

	cout << firstLetters << endl;
}