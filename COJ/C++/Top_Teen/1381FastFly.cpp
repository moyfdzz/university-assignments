#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int xCases;
	float dTotal, vUno, vDos, vMosca, dMosca;

	cin >> xCases;
	
	for (int i = 0; i < xCases; i++){
		cin >> dTotal;
		cin >> vUno;
		cin >> vDos;
		cin >> vMosca;

		dMosca = (vMosca * dTotal)/(vUno + vDos);

		cout << fixed << setprecision(2) << dMosca << endl;
	}

	return 0;
}