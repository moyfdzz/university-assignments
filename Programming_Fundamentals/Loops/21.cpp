#include <iostream>
using namespace std;

int main(){
	int dividend, divisor, countDiv = 0, remainder = 0;

	cin >> dividend >> divisor;

	if ((dividend > 0) && (divisor > 0)){
		while (dividend - divisor >= 0){
			countDiv++;
			dividend -= divisor;
		}
	}
	
	if (dividend - divisor > 0){
	  remainder = remainder + (dividend - divisor);
	}
	
	if (divisor > dividend){
	  remainder = dividend;
	}
	
	cout << "Division = " << countDiv << endl;
	cout << "Remainder = " << remainder << endl;
}