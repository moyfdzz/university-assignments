template <class T>
LinkedList<T> LinkedList<T>::split(int n) {
  if(n <= 0) {
    return *this;
    }

    Node<T>* curr = head;

	for(int i = 0; i < n; i++){
    curr = curr->getNext();
    }

	LinkedList<T> *lista2 = new LinkedList<T>();

	while(curr->getNext() != NULL) {
		lista2 += curr->getData();
        curr =  curr->getNext();
	}

	return *lista2;
}