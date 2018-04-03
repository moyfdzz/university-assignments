#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;

	for (int i = b; i > 0; i--){
		cout << a << " " << i << endl;
		a += 2;
	}
}