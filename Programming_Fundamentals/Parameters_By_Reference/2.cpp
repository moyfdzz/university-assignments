#include <iostream>
using namespace std;

void areaPer (int length, int width, int &area, int &perimeter){
    area = length * width;
    perimeter = 2*length + 2*width;
    
    cout << "El área es = " << area << endl;
    cout << "El perímetro es = " << perimeter << endl;
}

int main(){
  int  length, width, area = 0, perimeter = 0;
  
  cin >> length >> width;
  
  areaPer(length, width, area, perimeter);
}