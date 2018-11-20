#include "NodeT.h"

class BST {
    public:
        BST();
        ~BST();
        void add(int data);
        bool search(int data);
        void remove(int data);
        void print(int c);
        void ancestors(int data);
        int whatLevelamI(int data);
        int counter();
        int BSTHeight();
        void printLeft();
    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int pred(NodeT *r);
        int succ(NodeT *r);
        void preOrder(NodeT *r);
        void inOrder(NodeT *r);
        void postOrder(NodeT *r);
        void liberar(NodeT *r);
        void printLeaves(NodeT *r);
        void printLevelbyLevel();
        int cuenta(NodeT *r);
        int altura(NodeT *r);
        void recorrer(NodeT *r, int &counter);
};

BST::BST() {
    root = nullptr;
}

BST::~BST(){
    liberar(root);
}

int BST::howManyChildren(NodeT *r){
    int c = 0;
    if (r->getLeft() != nullptr){
        c++;
    }
    if (r->getRight() != nullptr){
        c++;
    }
    return c;
}

int BST::pred(NodeT *r){
    NodeT *aux = r->getLeft();
    while (aux->getRight() != nullptr){
        aux = aux->getRight();
    }
    return aux->getData();
}

int BST::succ(NodeT *r){
    NodeT *aux = r->getRight();
    while (aux->getLeft() != nullptr){
        aux = aux->getLeft();
    }
    return aux->getData();
}

void BST::preOrder(NodeT *r){
    if (r != nullptr){
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r){
    if (r != nullptr){
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r){
    if (r != nullptr){
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::liberar(NodeT *r){
    if (r != nullptr){
        liberar(r->getLeft());
        liberar(r->getRight());
        delete r;
    }
}

void BST::printLeaves(NodeT *r){
    if (r != nullptr){
        if (r->getLeft() == nullptr && r->getRight() == nullptr){
            cout << r->getData() << " ";
        } 
        else{
            printLeaves(r->getLeft());
            printLeaves(r->getRight());
        }
    }
}

void BST::printLevelbyLevel(){
    queue<NodeT*> nodesQueue;
    if (root != nullptr){
        nodesQueue.push(root);
        NodeT *curr;
        while (!nodesQueue.empty()){
            curr = nodesQueue.front();
            nodesQueue.pop();
           cout << curr->getData() << " ";
            if (curr->getLeft() != nullptr){
                nodesQueue.push(curr->getLeft());
            }
            if (curr->getRight() != nullptr){
                nodesQueue.push(curr->getRight());
            }
        }
    }
}

void BST::add(int data) {
    NodeT *father = nullptr;
    NodeT *curr = root;
    while(curr != nullptr) {
        if(curr->getData() == data) {
            return;
        }
        father = curr;
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    if(father == nullptr) {
        root = new NodeT(data);
    } else {
        if(father->getData() > data) {
            father->setLeft(new NodeT(data));
        } else {
            father->setRight(new NodeT(data));
        }
    }
}

bool BST::search(int data) {
    NodeT* curr = root;
    while(curr != nullptr) {
        if(curr->getData() == data) {
            return true;
        }
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    return false;
}

void BST::ancestors(int data){
    NodeT* curr  = root;
    stack<int> pila;
    while (curr != nullptr){
        if (curr->getData() == data){
            if (pila.empty()){
                cout << "NO EXITEN ANCESTROS"<<endl;
            }
            else{
                while (!pila.empty()){
                    cout << pila.top()<< " ";
                    pila.pop();
                }
                cout << endl;
            }
            return;
        }
        pila.push(curr->getData());
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    cout << "EL DATO NO EXISTE"<<endl;
}

int BST::whatLevelamI(int data){
    NodeT *curr = root;
    int nivel = 0;
    while (curr != nullptr){
        if (curr->getData() == data){
            return nivel;
        }
        nivel++;
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();        
    }
    return -1;
}

void BST::remove(int data){
    NodeT *curr = root;
    NodeT *father = nullptr;
    while (curr != nullptr && curr->getData() != data){
        father = curr;
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    if (curr == nullptr){
        return;
    }
    int c = howManyChildren(curr);
    switch (c){
        case 0 : if (father == nullptr){
                    root = nullptr;
                }
                else{
                    if (father->getData() > data){
                        father->setLeft(nullptr);
                    }
                    else{
                        father->setRight(nullptr);
                    }
                }
                delete curr;
                break;
        case 1: if (father == nullptr){
                    if (curr->getLeft() != nullptr){
                        root = curr->getLeft();
                    }
                    else{
                        root = curr->getRight();
                    }
                }
                else{
                    if (father->getData() > data){
                        if (curr->getLeft() != nullptr){
                            father->setLeft(curr->getLeft());
                        }
                        else{
                            father->setLeft(curr->getRight());
                        }
                    }
                    else{
                        if (curr->getLeft() != nullptr){
                            father->setRight(curr->getLeft());
                        }
                        else{
                            father->setRight(curr->getRight());
                        }
                    }
                }
                delete curr;
                break;
        case 2: int nodeData = succ(curr);
                remove(nodeData);
                curr->setData(nodeData);
                break;
        }

}

void BST::print(int c){
    switch(c){
        case 1: preOrder(root);
                break;
        case 2: inOrder(root);
                break;
        case 3: postOrder(root);
                break;
        case 4: printLeaves(root);
                break;
        case 5: printLevelbyLevel();
                break;
    }
    cout << endl;
}

int BST::counter(){
    return cuenta(root);
}

int BST::cuenta(NodeT *r){
    if (r == nullptr){
        return 0;
    }
    return 1+cuenta(r->getLeft())+cuenta(r->getRight());
}

int BST::BSTHeight(){
    return altura(root);
}

int BST::altura(NodeT *r){
    if (r == nullptr){
        return 0;
    }
    int izq = altura(r->getLeft());
    int der = altura(r->getRight());
    return 1 + (izq > der ? izq : der);
}

void BST::recorrer(NodeT *r, int &counter) {
    if (r != nullptr) {
        if (whatLevelamI(r->getData()) > counter) {
            cout << r->getData() << " ";

            counter++;
        }

        recorrer(r->getLeft(), counter);
        recorrer(r->getRight(), counter);
    }
}

void BST::printLeft() {
    int counter = -1;

    recorrer(root, counter);

    cout << endl;
}