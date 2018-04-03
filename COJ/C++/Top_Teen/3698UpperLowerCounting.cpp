#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

int main(){
	int wordSize, numUpper = 0, numLower = 0;
	string word;

  cin >> wordSize >> word;

	for (int i = 0; i < wordSize; i++){
		if (islower(word[i])){
			numLower++;
		}
		else if (isupper(word[i])){
			numUpper++;
		}
	}
	cout << numUpper << " " << numLower << endl;
}