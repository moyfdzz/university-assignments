#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int number, counter = 0;

	cin >> number;

	for(int i = 1; i <= number; i++){
		if (i % 3 == 0){
			if (counter == 3){
				cout << '%';
				counter = 0;
			}
		}
		else if (i % 2 != 0){
			cout << '*';
			counter++;
		}
		else if (i % 2 == 0){
			cout << '#';
			counter++;
		}
	}
}