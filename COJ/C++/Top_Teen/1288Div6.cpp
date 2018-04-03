#include <iostream>
#include <string>
using namespace std;

int main(){
	int p;
	cin >> p;
	while (p--){
		string n;
		int suma = 0;
	  	cin>>n;
		for (int i = 0; i < n.size(); i++){
			suma += int(n[i] - 48);
		}

		if (suma % 3 == 0 && int(n[n.size() - 1]) % 2 == 0){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
		return 0;
}