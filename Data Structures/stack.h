#include "Node.h"

template <class T>
class stack {
    public:
        stack();
        ~stack();
        T top();
        void push(T data);
        void pop();
        int size();
        bool empty();

    private:
        Node<T> *tope;
        int tam;
};

template <class T>
stack<T>::stack() {
    tope = NULL;
    tam = 0;
}

template <class T>
stack<T>::~stack() {
    Node<T> *curr = tope;

    while (tope != NULL) {
        tope = tope->getNext();
        delete curr;
        curr = tope;
    }
}

template <class T>
T stack<T>::top() {
    return tope->getData();
}

template <class T>
int stack<T>::size() {
    return tam;
}

template <class T>
bool stack<T>::empty() {
    return tope == NULL;
}

template <class T>
void stack<T>::push(T data) {
    tope = new Node<T>(data, tope);
    tam++;
}

template <class T>
void stack<T>::pop() {
    Node<T> *curr = tope;
    tope = tope->getNext();
    delete curr;
    tam--;
}