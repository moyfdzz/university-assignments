#include <iostream>
using namespace std;

int main(){
	int xParadas;
	int viejoPiso;
	int nuevoPiso = 1;
	int diferencia = 0;

	cin >> xParadas;

	int xTiempo = 0;
	for (int i = 0; i < xParadas; i++){
		cin >> viejoPiso;

		if (viejoPiso < nuevoPiso){
			diferencia = nuevoPiso - viejoPiso;
			xTiempo += diferencia;
		}
		else{
			diferencia = viejoPiso - nuevoPiso;
			xTiempo += diferencia;
		}
		viejoPiso = nuevoPiso;

		}
		xTiempo += nuevoPiso - 1;

		cout << xTiempo << endl;

	return 0;
}