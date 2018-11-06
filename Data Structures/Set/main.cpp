#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    set<int> miSet;
    int n, dato;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dato;
        miSet.insert(dato);
    }

    cout << "¿Cuál quieres buscar?" << endl;
    cin >> dato;

    set<int>::iterator it = miSet.find(dato);

    if (it == miSet.end()) {
        cout << "No está el elemento." << endl;
    }
    else {
        cout << "Sí está el elemento" << endl;
    }

    return 0;
}