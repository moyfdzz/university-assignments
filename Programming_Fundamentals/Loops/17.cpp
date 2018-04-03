#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int suma = 0;

	for (int i = 1; i <= n; i++){
		if (i & 2 != 0){
			suma += i;
			if (i != n)
				cout << i << " + ";
			else 
				cout << i;
		}
		else if (i % 2 == 0){
			suma += pow(i, 2);
			if (i != n)
				cout << i << " cuad " << " + ";
			else 
				cout << i << " cuad ";
		}
	}
	cout << " = " << suma << endl;
}