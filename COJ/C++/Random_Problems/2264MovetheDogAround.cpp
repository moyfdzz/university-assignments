#include <iostream>
using namespace std;

int main(){
	int cantR, cantC;
	int posR, posC, cantM;
	char dir;
	int cas;
	cin >> cantR >> cantC >> posR >> posC >> cantM;
	for (int i = 1; i <= cantM; i++){
		cin >> dir >> cas;
		switch (dir){
			case 'N' : posR += cas;
						break;
			case 'S' : posR -= cas;
						break;
			case 'W' : posC += cas;
						break;
			case 'E' : posC -= cas;
						break;
		}
	}
	cout << posR << " " << posC << endl;
}