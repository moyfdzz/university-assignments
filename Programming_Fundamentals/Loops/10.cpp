#include <iostream>
using namespace std;

int main(){
	int horas, minutos;

	cin >> horas >> minutos;

	while ((horas < 0) && (horas > 23) && (minutos < 0) && (minutos > 59)){
		cin >> horas >> minutos;
	}

	cout << horas << ":" << minutos;
}