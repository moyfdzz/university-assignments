#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList<string> list;

    list.addFirst("Meco");
    list.addFirst("Totoneco");
    list.addFirst("Seseleco");
    list.add("HEHe", 1);

    list.addLast("Hola");

    list.del(2);

    list.print();

    list.deleteAll();
    list.addLast("HEY");
    list.addFirst("HOLA");
    list.addLast("XD");

    list.print();

    list.reverse();

    list.print();

    list.shift(1);

    list.print();

    return 0;
}