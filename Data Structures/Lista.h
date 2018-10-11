//
//  Lista.h
//  Data Structures
//
//  Created by Moises Fernandez on 8/27/18.
//  Copyright © 2018 Moisés Fernández. All rights reserved.
//

#ifndef Lista_h
#define Lista_h

//Moisés Fernández Zárate A01197049

template <class T>
class Lista {
public:
    Lista();
    Lista(Lista<T> *lista);
    int getCant();
    T getDato(int indice);
    bool add(T dato);
    bool del(T dato);
    int search(T dato);
    void sort(bool ascendiente);
    void operator=(Lista<T> lista);
    bool operator==(Lista<T> lista);
    void print();
    
private:
    T arrDatos[10] = { false };
    int iCant;
};

template <class T>
Lista<T>::Lista() {
    this->iCant = 0;
}

template <class T>
int Lista<T>::getCant() {
    return iCant;
}

template <class T>
void Lista<T>::operator=(Lista<T> lista) {
    for(int i = 0; i < iCant; i++) {
        arrDatos[i] = lista->arrDatos[i];
    }
}

template <class T>
Lista<T>::Lista(Lista<T> *lista) {
    iCant = lista->getCant();
    
    arrDatos = lista->arrDatos;
}

template <class T>
T Lista<T>::getDato(int indice) {
    return arrDatos[indice];
}

template <class T>
bool Lista<T>::add(T dato) {
    bool agregar = false;
    
    for(int i = 0; i < this->getCant(); i++) {
        if(arrDatos[i] != 0) {
            agregar = true;
            arrDatos[iCant] = dato;
            iCant++;
        }
    }
    
    return agregar;
}

template <class T>
bool Lista<T>::del(T dato) {
    bool encontrado = false;
    
    for(int i = 0; i < iCant; i++) {
        if(arrDatos[i] == dato)
            encontrado = true;
        arrDatos[i] = 0;
        iCant--;
    }
    
    if(encontrado) {
        for(int i = 0; i < iCant; i++) {
            if(arrDatos[i] == 0 && arrDatos[i + 1] != 0)
                arrDatos[i] = arrDatos[i + 1];
        }
    }
    
    return encontrado;
}

template <class T>
int Lista<T>::search(T dato) {
    int posicion = -1;
    
    for(int i = 0; i < iCant; i++) {
        if(arrDatos[i] == dato)
            posicion = i;
    }
    
    return posicion;
}

template <class T>
void Lista<T>::sort(bool ascendiente) {
    T dato;
    
    if(ascendiente) {
        for(int i = 0; i < iCant; i++) {
            if(arrDatos[i] > arrDatos[i + 1]) {
                dato = arrDatos[i + 1];
                arrDatos[i + 1] = arrDatos[i];
                arrDatos[i] = dato;
            }
        }
    }
    else {
        for(int i = 0; i < iCant; i++) {
            if(arrDatos[i] < arrDatos[i + 1]) {
                dato = arrDatos[i];
                arrDatos[i] = arrDatos[i + 1];
                arrDatos[i + 1] = dato;
            }
        }
    }
}

template <class T>
bool Lista<T>::operator==(Lista<T> lista) {
    bool igual = true;
    
    sort(true);
    lista.sort(true);
    
    for(int i = 0; i < iCant; i++) {
        if(arrDatos[i] != lista.arrDatos[i])
            igual = false;
    }
    
    return igual;
}

template <class T>
void Lista<T>::print() {
    Node<T> *curr = head;
    while (curr != NULL) {
        cout << curr->getData() << " ";
        curr = curr->getNext();
    }

    cout << endl;
}

#endif /* Lista_h */
