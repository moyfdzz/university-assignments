#include <iostream>
#include <math.h> 
using namespace std;

void areaPerCircle (float radius, float &area, float &perimeter){
    area = 3.14 * pow(radius, 2);
    perimeter = 2 * 3.14 * radius;
    
    cout << "El área del círculo es = " << area << endl;
    cout << "El perímetro del círculo es = " << perimeter << endl;
}

int main(){
    float radius, area, perimeter;
    
    cin >> radius;
    
    areaPerCircle (radius, area, perimeter);
}