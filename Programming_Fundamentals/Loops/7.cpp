#include <iostream>
using namespace std;

int main(){
	int xTests;
	cin >> xTests;
	
	float resultado = 0;
	for (float i = 1; i <= xTests; i++){
	  resultado += 1/i;
		if (i != xTests){
			cout << 1 << "/" << i << " + ";
		}
		else if (i == xTests) {
			cout << 1 << "/" << i << " = ";
		}
	}
	
	cout << resultado << endl;
	
	return 0;
}