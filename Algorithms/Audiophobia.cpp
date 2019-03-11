#include <iostream>
#include <climits>
using namespace std;

void floyd(int D[20][20], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && max(D[i][k], D[k][j]) < D[i][j]) {
                    D[i][j] = max(D[i][k], D[k][j]);
                }
            }
        }
    }
}

int main () {
    int numberCases, C, Q, S, c1, c2, d;
    int D[20][20];

    cin >> numberCases;

    for (int i = 0; i < numberCases; i++) {
        cin >> C >> S >> Q;

        for (int j = 0; j < C; j++) {
            D[j][j] = 0;

            for (int k = j + 1; k < C; k++) {
                D[j][k] = D[k][j] = INT_MAX;
            }
        }

        for (int x = 0; x < S; x++) {
            cin >> c1 >> c2 >> d;

            D[c1 - 1][c2 - 1] = D[c2 - 1][c1 - 1] = d;
        }
        
        floyd(D, C);

        cout << "Case " << i + 1 << ":" << endl;

        for (int a = 0; a < Q; a++) {
            cin >> c1 >> c2;

            if (D[c1 - 1][c2 - 1] == INT_MAX) {
                cout << "no path" << endl;
            }
            else {
                cout << D[c1 - 1][c2 - 1] << endl;
            }
        }
    }
}