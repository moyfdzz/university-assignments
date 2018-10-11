#include <iostream>
using namespace std;

#include "BST.h"

int main () {
    BST miArbol;
    miArbol.add(11);
    miArbol.add(6);
    miArbol.add(19);
    miArbol.add(4);
    miArbol.add(8);
    miArbol.add(17);
    miArbol.add(43);
    miArbol.add(5);
    miArbol.add(10);
    miArbol.add(31);
    miArbol.add(49);
    //miArbol.print(1);
    // cout << endl;
    // miArbol.print(2);
    // cout << endl;
    // miArbol.print(3);
    // cout << endl;

    cout << "11 6 19 4 8 17 43 5 10 31 49" << endl;

    cout << "~Height~" << endl;
    cout << miArbol.height() << endl;
    cout << "~Ancestors~" << endl;
    miArbol.ancestors(5);
    cout << "~Level~" << endl;
    miArbol.whatLevelamI(20);
    cout << "~Level By Level~" << endl;
    miArbol.print(5);
    cout << endl;
    // miArbol.printLeaves();
    // cout << miArbol.count() << endl;

    return 0;
}