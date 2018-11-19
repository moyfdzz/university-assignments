template <class T>
int LinkedList<T>::get(int posicion) {
    T dato;
    Node<T> *curr = head;

    for(int i = 0; i < posicion; i ++) {
        curr = curr->getNext();
    }
    dato = curr->getData();

    return dato;
}

template <class T>
T LinkedList<T>::set(T dato, int posicion) {
    T datoAnterior;
    Node<T> *curr = head;

    for(int i = 0; i < posicion; i++) {
        curr = curr->getNext();
    }
    datoAnterior = curr->getData();
    curr->setData(dato);

    return datoAnterior;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {
    Node<T> *nodo1 = head, *nodo2 = head, *nodo3 = NULL;

    for(int i = 0; i < pos1; i++)
        nodo1 = nodo1->getNext();

    for(int i = 0; i < pos2; i++)
        nodo2 = nodo2->getNext();

		nodo3 = nodo1;
		nodo1 = nodo2;
		nodo2 = nodo3;
}
