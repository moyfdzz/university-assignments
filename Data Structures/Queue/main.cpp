#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    queue<int> miPila;
    miPila.push(400);
    miPila.push(300);
    miPila.push(600);

    cout << "La cantidad es: " << miPila.size() << endl;

    while (!miPila.empty()) {
        cout << miPila.front() << endl;
        miPila.pop();
    }

    return 0;
}