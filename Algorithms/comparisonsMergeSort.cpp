#include <iostream>
#include <vector>

using namespace std;

int contComp=0;

//&function

void Une(vector<int> &arreglo, int inicio, int mitad, int fin){
    int i = inicio, j = mitad + 1, k = 0;
    vector<int> aux(fin - inicio + 1);

    while (i <= mitad && j <= fin) {
        contComp++;

        if (arreglo[i] < arreglo[j]) {
            aux[k] = arreglo[i++];
        }
        else {
            aux[k] = arreglo[j++];
        }

        k++;
    }

    while (i <= mitad) {
        aux[k++] = arreglo[i++];
    }
    while (j <= fin) {
        aux[k++] = arreglo[j++];
    }
    
    for (int z = inicio; z <= fin; z++) {
        arreglo[z] = aux[z - inicio];
    }
}

void MergeSort(vector<int> &arreglo, int inicio, int fin){
    int mitad;

    if (inicio < fin) {
        mitad = (inicio + fin) / 2;
        MergeSort(arreglo, inicio, mitad);
        MergeSort(arreglo, mitad + 1, fin);
        Une(arreglo, inicio, mitad, fin);
    }
}

int main(){
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
	MergeSort(datos, 0, n-1);
	cout << contComp <<endl;
    
    for (int i=0; i<n; i++){
		cout<<datos[i]<< " ";
	}
}