#include <iostream>
#include <queue>
#include <stack>
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

    // if (miArbol.search(100)) {
    //     cout << "SI ENCONTRE EL 100" << endl;
    // }
    // else {
    //     cout << "NO ENCONTRE EL 100" << endl;
    // }
    // if (miArbol.search(200)) {
    //     cout << "SI ENCONTRE EL 200" << endl;
    // }
    // else {
    //     cout << "NO ENCONTRE EL 200" << endl;
    // }
    
    // cout << "~PreOrder~" << endl;
    // miArbol.print(1);
    // cout << endl << "~InOrder~" << endl;
    // miArbol.print(2);
    // cout << endl << "~PostOrder~" << endl;
    // miArbol.print(3);
    // cout << endl << "~Print Leaves~" << endl;
    // miArbol.print(4);
    // cout << endl << "~Level By Level~" << endl;
    // miArbol.print(5);
    // cout << endl << "~Height~" << endl;
    // cout << miArbol.height() << endl;
    // cout << "~Ancestors~" << endl;
    // miArbol.ancestors(5);
    // cout << "~Level~" << endl;
    // miArbol.whatLevelamI(20);
    // cout << "~Count~" << endl;
    // cout << miArbol.count() << endl;
    // miArbol.maxWidth();
    // cout << "~Nearest Relative~" << endl << miArbol.nearestRelative(17, 49) << endl;
    // cout << "~Max Width~" << endl << miArbol.maxWidth() << endl;    
    // miArbol.print(1);
    // cout << endl;
    // miArbol.mirror();
    // miArbol.print(1);
    // cout << endl;

    return 0;
}