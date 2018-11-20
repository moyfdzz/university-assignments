template <class T>
void LinkedList<T>::remove3()
{
    int counter = 0, counter2 = 0;
    Node<T> *curr = head;
	Node<T> *aux = head;

	if (this->isEmpty()) {
		return;
	}
	else if (size == 1 ) {
		deleteFirst();
		
		return;
	}
    else if (size == 2) {
        curr = curr->getNext();
        delete aux;
        size--;
		
        return;
    }

    while(curr->getNext() != nullptr) {   
        if(counter % 3 == 0) {
        	del(counter - counter2);
        	counter2++;
        }

		counter++;
        curr = curr->getNext();
    }

}