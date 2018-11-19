template <class T>
bool LinkedList<T>::check() {
    int numElementos = 0;
    Node<T>* curr = head;
    bool correcto = true;

    while(curr != NULL) {
        curr = curr->getNext();
        numElementos++;
    }

    if(size != numElementos) {
        correcto = false;
        size = numElementos;
    }
    
    return correcto;
}