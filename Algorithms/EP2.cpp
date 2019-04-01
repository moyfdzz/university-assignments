#include <iostream>
// Horse
// Matricula: A01197049
// Nombre: Moisés Fernández Zárate

using namespace std;
#define MAX 50

void printMatrix(int mat[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		    cout << mat[i][j] << " ";
		}

		cout << endl;
	}	
}

int horse(int n, int m){
	int mat[MAX][MAX] = {0};
    mat[n - 1][m - 1] = 1;
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if(mat[i][j] > 0) {
				if(i - 2 >= 0 && j - 1 >= 0) {
                    mat[i - 2][j - 1] += mat[i][j];
				}
				
                if(i - 1 >= 0 && j - 2 >= 0) {
					mat[i - 1][j - 2] += mat[i][j];
				}
			}
        }
    }

	//printMatrix(mat, n, m);

	return mat[0][0];
}

int main(){
	int n, m;
	cin >> n >> m;
	cout << horse(n, m)<<endl;
}