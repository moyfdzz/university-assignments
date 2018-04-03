#include <iostream>
using namespace std;

int main(){

	int edad = 12, regalo = 10;

	while (regalo < 1000){
		regalo *= 2;
		edad++;
	}

	cout << "La edad será " << edad << " años" << endl;

}