#include <iostream>
using namespace std;

int main(){
	int numero, factorial = 0;
	cin >> numero;
	
	factorial += numero;
	
	for (int restar = 1; restar < numero; restar++){
	  factorial *= (numero - restar);
	}
	
  cout << "!" << numero << " = " << factorial << endl;
}