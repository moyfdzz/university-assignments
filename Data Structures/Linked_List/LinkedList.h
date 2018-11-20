//
//  LinkedList.h
//  Data Structures
//
//  Created by Moises Fernandez on 8/24/18.
//  Copyright © 2018 Moisés Fernández. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

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
    void print();
    void reverse();
    void shift(int n);
    void spin(int n);
    bool operator==(const LinkedList<T> &lista2);
    void operator+=(const T dato);
    void operator+=(const LinkedList<T> &lista2);
    LinkedList(const LinkedList<T> &lista2);
    void operator=(const LinkedList<T> &lista2);
    LinkedList split(int n);
    bool check();
    void orderHalves(int n);
    
private:
    Node<T> *head;
    int size;
    void borraTodo();
};

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

template <class T>
void LinkedList<T>::borraTodo(){
    Node<T> * curr = head;
    while(head != NULL){
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
    
    // return(head == NULL);
}

template <class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
    if(this->isEmpty()){
        this->addFirst(data);
    }
    else{
        Node<T> *curr = head;
        while(curr->getNext() != NULL){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
void LinkedList<T>::deleteFirst(){
    if(!this->isEmpty()){
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteLast(){
    if(size <= 1){
        deleteFirst();
    }
    else{
        Node<T> *curr = head;
        while(curr->getNext()->getNext() != NULL){
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(NULL);
        size--;
    }
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
    if(pos > size){
        return false;
    }
    if(pos == 0){
        addFirst(data);
    }
    else if(pos == size){
        addLast(data);
    }
    else{
        Node<T> *curr = head;
        for(int i = 1; i < pos; i++){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    
    return true;
}

template <class T>
void LinkedList<T>::del(int pos){
    if(pos == 0){
        deleteFirst();
    }
    else if(pos == size-1){
        deleteLast();
    }
    else{
        Node<T> *curr = head;
        for(int i = 1; i < pos; i++){
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
T LinkedList<T>::get(int pos) {
    Node<T> *curr = head;
    for (int i = 0; i < pos; i++) {
        curr = curr->getNext();
    }
    return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos) {
    Node<T> *curr = head;
    for (int i = 0; i < pos; i++) {
        curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {
    if(pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >= size) {
        return false;
    }
    if(pos1 == 2){
        return true;
    }
    Node<T> *curr1 = head;
    
    int posMen = (pos1 < pos2 ? pos1 : pos2);
    int posMay = (pos1 > pos2 ? pos1 : pos2);
    
    /*
    if(pos1 > pos2)
        posMay = pos1;
     else
        posMay = pos2;
    */
    
    for(int i = 0; i < posMen; i++) {
        curr1 = curr1->getNext();
    }
    Node<T> *curr2 = curr1;
    for(int i = posMen; i < posMay; i++) {
        curr2 = curr2->getNext();
    }
    T dataAux = curr1->getData();
    curr1->setData(curr2->getData());
    curr2->setData(dataAux);
    return true;
}

template <class T>
void LinkedList<T>::print() {
    Node<T> *curr = head;

    while (curr != NULL) {
        std::cout << curr->getData() << " ";
        curr = curr->getNext();
    }

    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::reverse() {
    if(size < 1) {
        return;
    }

    Node<T>* curr1 = head;
    Node<T>* curr2 = curr1->getNext();

    head->setNext(NULL);

    while(curr2->getNext() != NULL) {
        head = curr2;
        curr2 = curr2->getNext();
        head->setNext(curr1->getNext());
        curr1 = head;
    }    
}

template <class T>
void LinkedList<T>::spin(int n) {
    if(n >= size) {
        reverse();
    }
    else if(n > 1) {
        int iTimes = size / n;
        int extraNodes = size % n;
        Node<T> *curr,*prev,*next,*first,*head2;
        
        first = head;
        prev = head;
        next = head->getNext();

        for(int i = 0; i < n - 1; i++) {
            head = next;
            next = next->getNext();
            head->setNext(prev);
            prev = head;
        }

        first->setNext(next);

        for(int i = 0; i < iTimes - 1 ; i++) {
            prev = next;
            head2 = next;
            curr = prev;
            next = next->getNext();

            for(int j = 0; j<n-1;j++) {
                curr = next;
                next = next->getNext();
                curr->setNext(prev);
                prev = curr;
            }

            first->setNext(curr);
            head2->setNext(next);
            first = head2;
        }

            prev = next;
            head2 = next;
            curr = prev;
            next = next->getNext();
        
        for(int i = 0; i < extraNodes - 1; i++) {
            curr = next;
            next = next->getNext();
            curr->setNext(prev);
            prev = curr;
        }

        first->setNext(curr);
        head2->setNext(nullptr);
    }
}

template <class T>
void LinkedList<T>::shift(int n) {
    Node<T>* curr = head;
    n %= size;

    for(int i = 0; i <= n; i++) {
        curr = curr->getNext();
    }

    Node<T>* curr2 = curr;

    while(curr2->getNext() != NULL) {
        curr2 = curr2->getNext();
    }

     curr2->setNext(head);
     head = curr->getNext();
     curr->setNext(NULL);
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &lista2) {
    if(size != lista2.size) {
        return false;
    }

    Node<T>* curr = head;
    Node<T>* curr2 = lista2.head;

    while(curr->getNext() != NULL) {
        if(curr->getData() != curr2->getData()) {
            return false;
        }

        curr = curr->getNext();
        curr2 = curr2->getNext();
    }

    return true;
}

template <class T>
void LinkedList<T>::operator+=(const T dato) {
    addLast(dato);
}

template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &lista2) {
    if(lista2.size == 0) {
        return;
    }

    Node<T>* curr = head;

    while(curr->getNext() != NULL) {
        curr = curr->getNext();
    }

    Node<T>* curr2 = lista2.head;

    while(curr2->getNext() != NULL) {
        curr->setNext(new Node<T>(curr2.getData()));
        curr = curr2->getNext();
        curr = curr->getNext();
        size++;
    }
}

template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &lista2) {
    deleteAll();

    Node<T> *curr = head;
    Node<T> *curr2 = lista2.head;
    
    addFirst(curr2->getData());
    curr2 = curr2->getNext();

    while(curr2 != NULL) {
        curr->setNext(new Node<T>(curr2->getData()));
        curr2 = curr2->getNext();
        curr = curr->getNext();
    }
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &lista2) {
    *this = lista2;
}

template <class T>
LinkedList LinkedList<T>::split(int n) {
    LinkedList<T> lista;
    Node<T>* curr = head;

    if(n <= 0) {
        lista.head = head;
        head = NULL;
    }
    if(n < size) {
        for(int i = 0; i < n; i++) {
        curr = curr->getNext();
        }

        lista.head = curr->getNext();
        size = n;
        lista.size = size - n;
        curr->setNext(NULL);
    }

    return lista;
}

template <class T>
bool LinkedList<T>::check() {
    int numElementos = 0;
    Node<T>* curr = head;
    bool correcto = true;

    while(curr->getNext() != NULL) {
        curr = curr->getNext();
        numElementos++;
    }

    if(size != numElementos) {
        correcto = false;
        size = numElementos;
    }
    
    return correcto;
}

#endif /* LinkedList_h */