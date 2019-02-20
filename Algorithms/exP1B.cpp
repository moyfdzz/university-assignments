/*
  Matricula: A01197049
  Nombre: Moisés Fernández Zárate
*/

#include <iostream>
#include <vector>

using namespace std;

bool llega(vector<int> &d){
    for (int i = 0; i < d.size(); i += d[i]) {
        if (d[i] <= d.size() - 1 - i) {
            if (d[i] == 0 && i != d.size() - 1) {
                return false;
            }
            else if (d[i] == 0 && i == d.size() - 1) {
                return true;
            }

            if (i + d[i] == d.size() - 1) {
                return true;
            }
        }
        else {
            return false;
        }
    }

	return true;
}

int main(){
	int n;
	cin >> n;
	vector<int> datos(n);
    
	for (int i=0; i<n; i++) {
	    cin>>datos[i];
	}

    cout << (llega(datos)? "YES" : "NO" )<<endl;
}

/*
Ejemplo 1
4
1 2 3 1

Ejemplo 2
5
1 2 0 1 2

Ejemplo 3
5
1 1 0 1 2

*/