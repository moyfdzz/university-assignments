#include <iostream>
using namespace std;

int main(){
	int n, xNum = 0;
	cout << "Teclea un número ";
	cin >> n;
	int suma = 0;
	if (n != 0)
	  suma += n;
	
	while (n != -99){
		cout << "Teclea un número ";
		cin >> n;
		xNum++;
		if (n != -99){
			suma += n;
		}	
	}

	cout << "La suma de los números es " << suma << " y se teclearon " << xNum << " números" << endl;
}