#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#include "NodeT.h"

class BST {
    public:
        BST();
        //~BST();
        void add(int data);
        bool search(int data);
        void remove(int data);
        void print(int c);
        int height(); //Tarea 1
        void ancestors(int data); //Tarea 1
        void whatLevelamI(int data); //Tarea 1
        int count(); //Tarea escrita
        int maxWidth(); //Tarea 2

    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int pred(NodeT *r);
        int succ(NodeT *r);
        void preOrder(NodeT *r);
        void inOrder(NodeT *r);
        void postOrder(NodeT *r);
        void libera(NodeT *r);
        int findHeight(NodeT *r); //Tarea 1
        void levelByLevel(NodeT *r); //Tarea 1
        void printLeaves(NodeT *r); //Tarea escrita
        int visitNodes(NodeT *r); //Tarea escrita
        int maxWidthAux(NodeT *r);
};

BST::BST() {
    root = nullptr;
}

void BST::libera(NodeT *r) {
    if (r != nullptr) {
        libera(r->getLeft());
        libera(r->getRight());

        delete r;
    }
}

bool BST::search(int data) {
    NodeT *curr = root;

    while (curr != nullptr) {
        if (curr->getData() == data) {
            return true;
        }

        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    return false;
}

void BST::add(int data) {
    NodeT *curr = root;
    NodeT *father = nullptr;

    while (curr != nullptr) {
        if (curr->getData() == data) {
            return;
        }

        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    if (father == nullptr) {
        root = new NodeT(data);
    }
    else {
        if (father->getData() > data) {
            father->setLeft(new NodeT(data));
        }
        else {
            father->setRight(new NodeT(data));
        }
    }
}

int BST::howManyChildren(NodeT *r) {
    int cant = 0;

    if (r->getLeft() != nullptr) {
        cant++;
    }
    if (r->getRight() != nullptr) {
        cant++;
    }

    return cant;
}

int BST::pred(NodeT *r) {
    NodeT *aux = r->getLeft();

    while (aux->getRight() != nullptr) {
        aux = aux->getRight();
    }

    return aux->getData();
}

int BST::succ(NodeT *r) {
    NodeT *aux = r->getRight();

    while (aux->getLeft() != nullptr) {
        aux = aux->getLeft();
    }

    return aux->getData();
}

void BST::remove(int data) {
    NodeT *curr = root;
    NodeT *father = nullptr;

    while (curr != nullptr && curr->getData() != data) {
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if (curr == nullptr) {
        return;
    }

    int ch = howManyChildren(curr);

    switch (ch) {
        case 0:
            if (father == nullptr) {
                root = nullptr;
            }
            else {
                if (father->getData() > data) {
                    father->setLeft(nullptr);
                }
                else {
                    father->setRight(nullptr);
                }
            }

            delete curr;
            
            break;
        case 1:
            if (father == nullptr) {
                if (curr->getLeft() != nullptr) {
                    root = curr->getLeft();
                }
                else {
                    root = curr->getRight();
                }
            }
            else {
                if (father->getData() > data) {
                    if (curr->getLeft() != nullptr) {
                        father->setLeft(curr->getLeft());
                    }
                    else {
                        father->setLeft(curr->getRight());
                    }
                }
                else {
                    if (curr->getLeft() != nullptr) {
                        father->setLeft(curr->getLeft());
                    }
                    else {
                        father->setRight(curr->getRight());
                    }
                }
            }

            delete curr;

            break;
        case 2:
            int x = pred(curr);
            remove(x);
            curr->setData(x);

            break;
    }
}

void BST::preOrder(NodeT *r) {
    if (r != nullptr) {
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r) {
    if (r != nullptr) {
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r) {
    if (r != nullptr) {
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::levelByLevel(NodeT *r) {
    queue<NodeT *> levelsQueue;
    NodeT *curr = r;

    if (curr == nullptr) {
        return;
    }

    levelsQueue.push(curr);

    while (!levelsQueue.empty()) {
        cout << curr->getData() << " ";

        levelsQueue.pop();

        if (curr->getLeft() != nullptr) {
            levelsQueue.push(curr->getLeft());
        }
        if (curr->getRight() != nullptr) {
            levelsQueue.push(curr->getRight());
        }

        curr = levelsQueue.front();
    }
}

void BST::printLeaves(NodeT *r) {
    NodeT * curr = r;

    if (curr == nullptr)
        return;

    if (curr->getLeft() == nullptr && curr->getRight() == nullptr) {
        cout << curr->getData() << " ";
    }
    else {
        printLeaves(curr->getLeft());
        printLeaves(curr->getRight());
    }
}

void BST::print(int c) {
// 1 - PreOrder
// 2 - InOrder
// 3 - PostOrder
// 4 - Prints only the leaves of the BST
// 5 - Prints the BST level by level

    switch (c) {
        case 1:
            preOrder(root);

            break;
        case 2:
            inOrder(root);

            break;
        case 3:
            postOrder(root);

            break;
        case 4:
            printLeaves(root);

            break;
        case 5:
            levelByLevel(root);

            break;
    }
}

int BST::findHeight(NodeT *r) {
    NodeT *curr = r;

    if (curr == nullptr) {
        return 0;
    }

    int leftSubtree = findHeight(curr->getLeft());
    int rightSubtree = findHeight(curr->getRight());

    return 1 + (leftSubtree > rightSubtree ? leftSubtree: rightSubtree);
}

int BST::height() {
    return findHeight(root);
}

void BST::ancestors(int data) {
    NodeT *curr = root;
    stack<int> ancestorsStack;
    bool found = false;

     while (curr != nullptr && !found) {
         if (curr->getData() == data) {
             if (ancestorsStack.empty()) {
                 cout << "NO EXISTEN ANCESTROS" << endl;
             }
             else {
                while (!ancestorsStack.empty()) {
                    cout << ancestorsStack.top() << " ";
                    ancestorsStack.pop();
                }
             }
             cout << endl;
             found = true;
         }

         ancestorsStack.push(curr->getData());
         curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
     }

    if (!found)
        cout << "EL DATO NO EXISTE" << endl;
}

void BST::whatLevelamI(int data) {
    int level = -1;
    NodeT *curr = root;
    bool found = false;

    while (curr != nullptr && !found) {
        level++;

        if (curr->getData() == data) {
            cout << level << endl;
            found = true;
        }

        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    if (!found) {
        cout << -1 << endl;
    }
}

int BST::visitNodes(NodeT *r) {
    NodeT *curr = r;

    if (curr == nullptr) {
        return 0;
    }

    return visitNodes(curr->getLeft()) + visitNodes(curr->getRight()) + 1;
}

int BST::count() {
    return visitNodes(root);
}

int BST::maxWidthAux(NodeT *r) {
    queue<NodeT *> nodesQueue;
    NodeT *curr = r;

    if (curr == nullptr) {
        return;
    }

    nodesQueue.push(curr);

    while (!nodesQueue.empty()) {
        nodesQueue.pop();

        if (curr->getLeft() != nullptr) {
            nodesQueue.push(curr->getLeft());
        }
        if (curr->getRight() != nullptr) {
            nodesQueue.push(curr->getRight());
        }

        curr = nodesQueue.front();
    }
}