#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void invertPhrase(string phrase, string &invertedPhrase)
{
	for (int counter = 0; counter < phrase.length(); counter++)
	{
		tolower(phrase[phrase.length() - 1 - counter]);
		invertedPhrase += phrase[phrase.length() - 1 - counter];
	}
}

void checkIfPalindrome(string phrase, string invertedPhrase, bool &isPalindrome)
{
	for (int counter = 0; counter < phrase.length(); counter++)
	{
		if (invertedPhrase[counter] != phrase[phrase.length() - counter])
		{
			cout << "No es un palíndromo" << endl;
			isPalindrome = 0;
			break;
		}
	}

	if (isPalindrome)
	{
		cout << "Sí es un palíndromo" << endl;
	}

}

int main()
{
	string phrase, invertedPhrase;
	bool isPalindrome = 1;

	cout << "Introduzque la frase" << endl;
	getline(cin, phrase);

	invertPhrase(phrase, invertedPhrase);
	checkIfPalindrome(phrase, invertedPhrase, isPalindrome);

	cout << "La frase es: " << phrase << endl;
	cout << "La frase invertida es: " << invertedPhrase << endl;

}