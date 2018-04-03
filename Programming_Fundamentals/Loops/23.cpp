#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int number;

	cin >> number;

	for(int i = 1; i <= number; i++){
		if (i % 2 != 0){
			cout << '*';
		}
		else{
			cout << '#';
		}
	}
}