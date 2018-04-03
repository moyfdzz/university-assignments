#include <iostream>
using namespace std;

int main(){
	int arr[1000];

	int t, n, b, g, m;

	cin >> t;

	for (int i = 1; i<=t; i++){
		cin >> n;
		m = 0;
		for (int j = 0; j < n; j++){
			cin >> b >> g;
			arr[j] = b + g;
			if (m < b + g){
				m = b + g;
			}
		}
		int acum = 0;
		for (int j = 0; j < m; j++){
			acum += (m - arr[j]);
		}
		cout << acum << endl;
	}
}