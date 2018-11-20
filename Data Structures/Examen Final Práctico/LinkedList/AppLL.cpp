#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(){
    LinkedList<int> lista;

    lista.addLast(5);
    lista.addLast(3);
    lista.addLast(1);
    lista.addLast(2);
    lista.addLast(4);

    lista.print();

    lista.remove3();

    lista.print();
}