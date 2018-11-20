#include "Node.h"

template <class T>
class LinkedList{
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty();
		void addFirst(T data);
		void addLast(T data);
		bool add(T data, int pos);
		void deleteFirst();
		void deleteLast();
		void del(int pos);
		int deleteAll();
		T get(int pos);
		T set(T data, int pos);
		bool change(int pos1, int pos2);
		int getSize();
		void print();
		void remove3();
	private:
		Node<T> *head;
		int size;
		void borraTodo();
};

template <class T>
LinkedList<T>::LinkedList(){
	head = nullptr;
	size = 0;
}

template <class T>
void LinkedList<T>::borraTodo(){
	Node<T> *curr = head;
	while (head != nullptr){
		head = head->getNext();
		delete curr;
		curr = head;
	}
}

template <class T>
LinkedList<T>::~LinkedList(){
	borraTodo();
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return (size == 0);

//	return (head == nullptr);
}

template <class T>
void LinkedList<T>::addFirst(T data){
	head = new Node<T>(data, head);
	size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
	if (this->isEmpty()){
		this->addFirst(data);
	}
	else{
		Node<T> *curr = head;
		while (curr->getNext() != nullptr){
			curr = curr->getNext();
		}
		curr->setNext(new Node<T>(data));
		size++;
	}
}

template <class T>
void LinkedList<T>::deleteFirst(){
	if (!this->isEmpty()){
		Node<T> *curr = head;
		head = head->getNext();
		delete curr;
		size--;
	}
}

template <class T>
void LinkedList<T>::deleteLast(){
	if (size <= 1){
		deleteFirst();
	}
	else{
		Node<T> *curr = head;
		while (curr->getNext()->getNext() != nullptr){
			curr = curr->getNext();
		}
		delete curr->getNext();
		curr->setNext(nullptr);
		size--;
	}
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
	if (pos > size){
		return false;
	}
	if (pos == 0){
		addFirst(data);
	}
	else if (pos == size){
		addLast(data);
	}
	else{
		Node<T> *curr=head;
		for (int i=1; i<pos; i++){
			curr = curr->getNext();
		}
		curr->setNext(new Node<T>(data,curr->getNext()));
		size++;
	}
	return true;
}

template <class T>
void LinkedList<T>::del(int pos){
	if (pos == 0){
		deleteFirst();
	}
	else if (pos == size-1){
		deleteLast();
	}
	else{
		Node<T> *curr = head;
		for (int i=1; i<pos; i++){
			curr = curr->getNext();
		}
		Node<T> *temp = curr->getNext();
		curr->setNext(temp->getNext());
		delete temp;
		size--;
	}
}

template <class T>
int LinkedList<T>::deleteAll(){
	borraTodo();
	int cant = size;
	size = 0;
	return cant;
}

template <class T>
T LinkedList<T>::get(int pos){
	Node<T> *curr = head;
	for (int i=0; i<pos; i++){
		curr = curr->getNext();
	}
	return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos){
	Node<T> *curr = head;
	for (int i=0; i<pos; i++){
		curr = curr->getNext();
	}
	T dataAux = curr->getData();
	curr->setData(data);
	return dataAux;	
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2){
	if (pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >= size){
		return false;
	}
	if (pos1 == pos2){
		return true;
	}
	Node<T> *curr1 = head;

	int posMen = (pos1 < pos2 ? pos1 : pos2);
	int posMay = (pos1 > pos2 ? pos1 : pos2);

/*	if (pos1 > pos2)
		posMay = pos1;
	else
		posMay = pos2;
*/
	for (int i=0; i<posMen; i++){
		curr1 = curr1->getNext();
	}
	Node<T> *curr2 = curr1;
	for (int i=posMen; i<posMay; i++){
		curr2 = curr2->getNext();
	}
	T dataAux = curr1->getData();
	curr1->setData(curr2->getData());
	curr2->setData(dataAux);
	return true;
}

template <class T>
int LinkedList<T>::getSize(){
	return size;
}

template <class T>
void LinkedList<T>::print(){
	Node<T> *curr = head;
	cout << "INICIO"<<endl;
	while (curr != nullptr){
		cout << curr->getData()<< " ";
		curr = curr->getNext();
	}
	cout << endl<<"FIN"<<endl;
}

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