#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main(){
	int x1, x2, y1, y2, sumaX, sumaY, absX, absY, xCases, sumaTotal;

	scanf("%i", &xCases);

	for (int i = 0; i < xCases; i++){
		scanf("%i %i %i %i", &x1, &y1, &x2, &y2);
		sumaX = x2 - x1;
		sumaY = y2 - y1;
		absX = abs(sumaX);
		absY = abs(sumaY);
		sumaTotal = absX + absY;
		printf("%i \n", sumaTotal);
	}
}