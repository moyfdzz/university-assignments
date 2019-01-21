#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, pos, nZeros = 0, nOnes = 0;
    string input;

    cin >> n >> input;

    for (int i = 0; i < n; i++) {
        if (input[i] == '1')
            nOnes++;
        else if (input[i] == '0')
            nZeros++;
    }

    cout << (nOnes > nZeros ? nOnes - nZeros : nZeros - nOnes) << endl;

    return 0;
}