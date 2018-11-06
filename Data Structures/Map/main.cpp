#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> miMap;

    int n, edad;
    string nombre;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nombre >> edad;

        miMap.insert(pair<string, int>(nombre, edad));
    }

    cout << "¿De quién deseas la edad?" << endl;
    cin >> nombre;

    cout << miMap[nombre] << endl;
}