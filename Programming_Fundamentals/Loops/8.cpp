#include <iostream>
using namespace std;

int main(){
	int xTests;
	cin >> xTests;

	for (int i = 1; i <= xTests; i++){
		cout << i << " " << ',' << " ";
	}
	for (int i = xTests - 1; i > 0; i--){
		if (i == 1)
			cout << i << endl;
		else
			cout << i << " " << ',' << " ";
	}
}