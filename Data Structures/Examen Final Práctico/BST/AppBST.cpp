#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#include "BST.h"
// #include "printLeft.h"

int main(){
	BST miArbol;

	miArbol.add(50);
	miArbol.add(45);
	miArbol.add(55);
	miArbol.add(40);
	miArbol.add(46);
	miArbol.add(65);
	miArbol.add(35);
	miArbol.add(41);
	miArbol.add(49);
	miArbol.add(64);
	miArbol.add(70);
	miArbol.add(48);

	miArbol.print(1);
	miArbol.print(2);
	miArbol.print(3);

	return 0;
}