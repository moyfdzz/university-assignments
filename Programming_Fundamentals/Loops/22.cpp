#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int number, divisor = 2, alternator = 1;
	float result = 0, numerator = 1;

	cin >> number;

	for (int i = 1; i <= number; i++){
		if (i % 2 != 0){
			if (alternator != number){
				result += alternator;
				cout << alternator << " + ";
				alternator += 2;
			}
			else {
				result += alternator;
				cout << alternator << " = ";
			}
		}
		else if (i % 2 == 0){
			if (divisor != number){
				result = result + (numerator/divisor);
				cout << numerator << "/" << divisor << " + ";
				divisor += 2;
			}
			else {
				result = result + (numerator/divisor);
				cout << numerator << "/" << divisor << " = ";
			}
		}
	}

	cout << setprecision(3) << result << endl;
}