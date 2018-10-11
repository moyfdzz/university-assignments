#include "Node.h"

template <class T>
class LinkedList {
    public: 
        LinkedList();
        bool isEmpty();
        void addFirst(T dato);
        void addLast(T dato);
        bool add(T dato, int pos);
        void deleteFirst();
        void deleteLast();
        void del(int pos);
        int deleteAll();
        T get(int pos);
        T set(T data, int pos);
        bool change(int pos1, int pos2);
        void print();
        void reverse();

    private:
        Node<T>* head;
        int size;
};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    size = 0;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return(size == 0);
}

template <class T>
void LinkedList<T>::addFirst(T dato) {

}



// void addLast(T dato);
// bool add(T dato, int pos);
// void deleteFirst();
// void deleteLast();
// void del(int pos);
// int deleteAll();
// T get(int pos);
// T set(T data, int pos);
// bool change(int pos1, int pos2);
// void print();
// void reverse();