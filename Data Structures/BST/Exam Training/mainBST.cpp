#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#include "BSTPractice.h"

int main () {
    BST miArbol;
    miArbol.add(4);
    miArbol.add(2);
    miArbol.add(1);
    miArbol.add(3);
    //miArbol.print(1);
    // cout << endl;
    // miArbol.print(2);
    // cout << endl;
    // miArbol.print(3);
    // cout << endl;

    cout << "4 2 1 3" << endl;

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

    // BST arbol2(miArbol); //BST arbol2 = BST(miArbol);

    // if (miArbol == arbol2)
    //     cout << "iguales" << endl;
    // else
    //     cout << "diferentes" << endl;

    // cout << "maxWidth de arbol1 = " << miArbol.maxWidth() << endl;
    // cout << "maxWidth de arbol2 = " << arbol2.maxWidth() << endl;

    // cout << "~arbol 2~" << endl;
    // arbol2.print(1);
    // arbol2.mirror();
    // cout << endl << "~inverso de arbol2~" << endl;
    // arbol2.print(1);
    // cout << endl <<  "nearestRelative de 31 y 49 en el arbol2 = " << arbol2.nearestRelative(31, 49) << endl;
    // miArbol.printPathsToLeaves();
    // miArbol.printMinValue();
    // miArbol.printMaxValue();

    // miArbol.mirror();

    // if (miArbol.isBST())
    //     cout << "It's a BST!" << endl;
    // else
    //     cout << "It's not a BST!" << endl;
    // miArbol.printKthDistance(1);
    // cout << miArbol.descendants(11) << endl;
    // cout << miArbol.getWidth(2) << endl;

    //miArbol.printSingles();

    cout << miArbol.maxWidth() << endl;

    return 0;
}