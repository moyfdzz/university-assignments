#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string word;

	cin >> n;

	while (n--){
		int suma = 0;
	  	cin >> word;
	  	int tamPalabra = word.size();
		for (int i = 1; i < tamPalabra - 1; i++){
			suma ++; 
		}
	if (word.size() > 10){
	cout << word[0] << suma << word[word.size() - 1] << endl;
	}
	else 
		cout << word << endl;
	}
	return 0;
}