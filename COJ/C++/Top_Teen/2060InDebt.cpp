#include <iostream>
using namespace std;

int main(){
	int n, prestamo, suma = 0, idas = 0;
	cin >> n;

  if (n != -1){
	  for(int i = 0; i < n; i++){
		  cin >> prestamo;
		  suma += prestamo;
		  if (suma % 100 == 0){
			  idas++;
			  suma = 0;
		  }
	  }
  }
	else if (n == -1)
	  return 0;
	cout << idas << endl;
}