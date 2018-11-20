#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#include "BST.h"
// #include "printLeft.h"

int main(){
	BST miArbol;

	miArbol.add(8);
	miArbol.add(3);
	miArbol.add(10);
	miArbol.add(1);
	miArbol.add(6);
	miArbol.add(14);
	miArbol.add(4);
	miArbol.add(7);
	miArbol.add(13);

	miArbol.printLeft();

	return 0;
}