#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 10

void iniMatAdj(bool matAdj[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matAdj[i][j] = false;
        }
    }
}

void leeMatAdj(bool matAdj[N][N], int e) {
    int a, b;

    for (int i = 1; i <= e; i++) {
        cin >> a >> b;

        matAdj[a - 1][b - 1] = matAdj[b - 1][a - 1] = true;
    }
}

void printMatAdj(bool matAdj[N][N], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << (matAdj[i][j] ? "T" : "F") << "\t";
        }
        cout << endl;
    }
}

void BFS(bool matAdj[N][N], int v) {
    queue<int> fila;
    fila.push(0);
    int data;
    vector<bool> status(N, false);
    status[0] = true;

    while (!fila.empty()) {
        data = fila.front();
        fila.pop();
        cout << (data + 1) << " ";

        for (int j = 0; j < v; j++) {
            if (matAdj[data][j] && !status[j]) {
                fila.push(j);
                status[j] = true;
            }
        }
    }
    cout << endl;
}

int main () {
    bool matAdj[N][N];
    int v, e;

    cin >> v >> e;

    iniMatAdj(matAdj);
    leeMatAdj(matAdj, e);
    printMatAdj(matAdj, v);
    BFS(matAdj, v);

    return 0;
}