#include <iostream>
#include <math.h> 
using namespace std;

void areaVolumeCilinder (float radius, float height, float &area, float &volume){
    area = 2 * (3.14 * pow(radius, 2)) + height * (2 * 3.14 * radius);
    volume = (3.14 * pow(radius, 2)) * height;
    
    cout << "El área del cilíndro es = " << area << endl;
    cout << "El volúmen del cilíndro es = " << volume << endl;
}

int main(){
    float radius, height, area, volume;
    
    cin >> radius >> height;
    
    areaVolumeCilinder (radius, height, area, volume);
}