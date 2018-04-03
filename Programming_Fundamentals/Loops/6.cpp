#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;

	for (int i = a; i < b; i += 5){
		cout << i << " ";
	}
	cout << endl;
}
