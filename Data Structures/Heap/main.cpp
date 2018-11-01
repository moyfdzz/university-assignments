#include <iostream>
using namespace std;
#include "Priority.h"

int main() {
    Priority lista1, lista2(false);

    int array[10] = {1, 5, 2, 8, 7, 9, 10, 3, 6, 4};

    for (int i = 0; i < 10; i++) {
        lista1.push(array[i]);
        lista2.push(array[i]);
    }

    lista1.print();
    lista2.print();

    cout << endl;
}