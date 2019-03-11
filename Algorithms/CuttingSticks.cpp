#include <iostream>
using namespace std;

int main () {
    int stickLength, n, ci;

    cin >> stickLength;

    if (stickLength) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ci;
        }
    }
    else {
        return 0;
    }

    return 0;
}