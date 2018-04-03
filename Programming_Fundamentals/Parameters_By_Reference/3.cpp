#include <iostream>
using namespace std;

void secEquiv (int &horas, int &minutos, int &segundos){
    horas = segundos / 3600;
    segundos -= horas * 3600;
    minutos = segundos / 60;
    segundos -= minutos * 60;
    
    cout << "Horas equivalentes = " << horas << endl;
    cout << "Minutos equivalentes = " << minutos << endl;
    cout << "Segundos equivalentes = " << segundos << endl;
}

int main(){
  int horas, minutos, segundos;
  
  cin >> segundos;
  
  secEquiv (horas, minutos, segundos);
}