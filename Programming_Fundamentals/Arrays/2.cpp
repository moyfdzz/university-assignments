#include <iostream>
using namespace std;

void sumParImp(int arr[], int sizeArr, int &sumPar, int &sumImp){
	cin >> sizeArr;
	
	for (int i = 0; i < sizeArr; i++){
		cin >> arr[i];
	}

	for (int i = 0; i < sizeArr; i++){
		if (i % 2 == 0){
			sumPar += arr[i];
		}
		else if (i % 2 != 0){
			sumImp += arr[i];
		}
	}

	cout << "La suma de los números de las casillas pares es = " << sumPar << endl;
	cout << "La suma de los números de las casillas impares es = " << sumImp << endl;
}

int main(){
	int arr[20], sizeArr, sumPar = 0, sumImp = 0;

	sumParImp(arr, sizeArr, sumPar, sumImp);
}