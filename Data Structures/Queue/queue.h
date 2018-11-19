#include "Node.h"

template <class T>
class queue {
    public:
        queue();
        ~queue();
        T front();
        void push(T data);
        void pop();
        int size();
        bool empty();

    private:
        Node<T> *ultimo;
        int tam;
};

template <class T>
queue<T>::queue() {
    ultimo = NULL;
    tam = 0;
}

template <class T>
queue<T>::~queue() {
    if (ultimo != NULL) {
        Node<T> *curr = ultimo->getNext();
        ultimo->setNext(NULL);
        ultimo = curr;

        while (ultimo != NULL) {
            ultimo = ultimo->getNext();
            delete curr;
            curr = ultimo;
        }
    }
}

template <class T>
T queue<T>::front() {
    return ultimo->getNext()->getData();
}

template <class T>
void queue<T>::push(T data) {
    if (ultimo == NULL) {
        ultimo = new Node<T>(data);
        ultimo->setNext(ultimo);
    }
    else {
        ultimo->setNext(new Node<T>(data, ultimo->getNext()));
        ultimo = ultimo->getNext();
    }
    
    tam++;
}

template <class T>
void queue<T>::pop() {
    Node<T> *curr = ultimo->getNext();

    if (ultimo->getNext() == ultimo) {
        ultimo = NULL;
    }
    else {
        ultimo->setNext(curr->getNext());
    }
}

template <class T>
int queue<T>::size() {
    return tam;
}

template <class T>
bool queue<T>::empty() {
    return ultimo == NULL;
}