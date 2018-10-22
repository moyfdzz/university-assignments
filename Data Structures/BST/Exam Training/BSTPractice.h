#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#include "NodeT.h"

class BST {
    public:
        BST();
        ~BST();
        void add(int data);
        bool search(int data);
        void remove(int data);
        void print(int c);
        int height(); //Tarea 1
        void ancestors(int data); //Tarea 1
        void whatLevelamI(int data); //Tarea 1
        int count(); //Tarea escrita
        int maxWidth(); //Tarea 2
        int nearestRelative(int a, int b); //Tarea 2
        bool operator==(BST secondTree); //Tarea 2
        BST(const BST &otherTree); //Tarea 2
        void mirror(); //Tarea 2
        void printPathsToLeaves(); //Practice
        void printMinValue(); //Practice
        bool isBST(); //Practice
        void printMaxValue(); //Practice
        void printKthDistance(int k); //Practice (Nodes at k distance from root)
        int descendants(int data); //Practice (Prints descendants of received number)
        int getWidth(int level); //Practice (Get how many nodes in a level)
        void printSingles(); //Practice (Prints nodes that have no siblings)

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
        bool checkIfEqual(NodeT *r1, NodeT *r2); //Tarea 2
        void copyNodes(NodeT *rOld, NodeT *rNew); //Tarea 2
        void swapNodes(NodeT *r); //Tarea 2
        void printWithStack(NodeT *r, stack<int> st); //Practice
        bool childrenAreValid(NodeT *r); //Practice
        void findKthElement(NodeT *r, int counter); //Practice
        int countDescendants(NodeT *curr); //Practice
        void singles(NodeT *r); //Practice
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

BST::~BST() {
    libera(root);
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
// 6 - Prints the paths to the leaves of the BST

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

int BST::maxWidth() {
    NodeT *curr = root;

    if(curr != nullptr) {
        queue<NodeT *> nodesBST;
        nodesBST.push(curr);
        int ancestors = 1, successors = 0, maxWidthBST = 1;

        do {
            successors = 0;

            for(int i = 0; i < ancestors; i++) {
                curr = nodesBST.front();

                if(curr->getLeft() != nullptr) {
                    nodesBST.push(curr->getLeft());
                    successors++;
                } 

                if(curr->getRight() != nullptr) {
                    nodesBST.push(curr->getRight());
                    successors++;
                }

                nodesBST.pop();
            }

            if(maxWidthBST < ancestors)
                maxWidthBST = ancestors;

            ancestors = successors;
        }while(successors > 0);
        
        return maxWidthBST;
    }

    return 0;
}

int BST::nearestRelative(int a, int b) {
    NodeT *curr = root;
    int nearestAncestor = curr->getData();
    bool found = false;

    while (curr != nullptr && !found) {
        if (curr->getData() > a && root->getData() > b) 
           curr = curr->getLeft();
        else if (curr->getData() < a && curr->getData() < b) 
           curr = curr->getRight();
        else {
            nearestAncestor = curr->getData();
            found = true;
        }
    }

    return nearestAncestor;
}

bool BST::checkIfEqual(NodeT *r1, NodeT *r2) {
    if (r1 == nullptr && r2 == nullptr)
        return true;
    
    if ((r1 == nullptr && r2 != nullptr) || (r1 != nullptr && r2 == nullptr))
        return false;

    if (r1->getData() != r2->getData())
        return false;
    
    return checkIfEqual(r1->getLeft(), r2->getLeft()) && checkIfEqual(r1->getRight(), r2->getRight());
}

bool BST::operator==(BST secondTree) {
    return checkIfEqual(root, secondTree.root);
}

void BST::copyNodes(NodeT *rOld, NodeT *rNew)
{
    if (rOld == nullptr)
        return;

    if (rOld->getLeft() != nullptr)
        rNew->setLeft(new NodeT(rOld->getLeft()->getData()));

    if (rOld->getRight() != nullptr)
        rNew->setRight(new NodeT(rOld->getRight()->getData()));

    copyNodes(rOld->getLeft(), rNew->getLeft());
    copyNodes(rOld->getRight(), rNew->getRight());
}

BST::BST(const BST &otherTree)
{
    if (otherTree.root == nullptr) {
        root = nullptr;
        return;
    }

    root = new NodeT(otherTree.root->getData());

    copyNodes(otherTree.root, root);
}

void BST::swapNodes(NodeT *r) {
    if (r == nullptr) {
        return;
    }

    swapNodes(r->getLeft());
    swapNodes(r->getRight());

    NodeT *temp = r->getLeft();

    r->setLeft(r->getRight());
    r->setRight(temp);
}

void BST::mirror() {
    swapNodes(root);
}

void BST::printWithStack(NodeT *r, stack<int> st)
{
    if (r == nullptr)
        return;
        
    if (r->getRight() == nullptr && r->getLeft() == nullptr) {
        st.push(r->getData());

        while (!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }

        cout << endl;

        return;
    }

    st.push(r->getData());

    printWithStack(r->getLeft(), st);
    printWithStack(r->getRight(), st);
}

void BST::printPathsToLeaves() {
    stack<int> st;
    printWithStack(root, st);
}

void BST::printMinValue() {
    NodeT *curr = root;

    if (curr == nullptr) {
        cout << "Empty BST." << endl;
    }

    while (curr->getLeft() != nullptr) {
        curr = curr->getLeft();
    }

    cout << curr->getData() << endl;
}

bool BST::childrenAreValid(NodeT *r)
{
    if (r == nullptr)
        return true;

    bool valid = true;

    if (r->getLeft() != nullptr)
        valid = r->getLeft()->getData() < r->getData();

    if (r->getRight() != nullptr)
        valid = valid && r->getRight()->getData() > r->getData();

    return childrenAreValid(r->getLeft()) && childrenAreValid(r->getRight()) && valid;
}

bool BST::isBST()
{
    return childrenAreValid(root);
}

void BST::printMaxValue() {
    NodeT *curr = root;

    if (curr == nullptr) {
        cout << "Empty BST." << endl;
    }

    while (curr->getRight() != nullptr) {
        curr = curr->getRight();
    }

    cout << curr->getData() << endl;
}

void BST::findKthElement(NodeT *r, int counter) {
    if (r == nullptr)
        return;

    if (counter == 0) {
        cout << r->getData() << endl;
        return;
    }

    findKthElement(r->getLeft(), counter - 1);
    findKthElement(r->getRight(), counter - 1);
}


void BST::printKthDistance(int k) {
    findKthElement(root, k);
}

int BST::countDescendants(NodeT *curr){
    if(curr == nullptr){
        return 0;
    }

    return countDescendants(curr->getLeft()) + countDescendants(curr->getRight()) + 1; 
}

int BST::descendants(int data){
    if(root == nullptr){
        return -1;
    }

    NodeT *curr = root;

    while(curr!= nullptr && curr->getData() != data){
        curr = (data > curr->getData()) ? curr->getRight() : curr->getLeft();
    }

    return countDescendants(curr) - 1;
}

int BST::getWidth(int level) {
    NodeT *curr = root;

    if (curr == nullptr) {
        return 0;
    }

    queue<NodeT *> queue;
    queue.push(curr);
    int lv = 0;

    while (!queue.empty()) {
        int queueSize = queue.size();
        
        if (lv == level) {
            return queueSize;
        }

        while (queueSize != 0) {
            if (queue.front()->getLeft() != nullptr) {
                queue.push(queue.front()->getLeft());
            }
            if (queue.front()->getRight() != nullptr) {
                queue.push(queue.front()->getRight());
            }

            queueSize--;
            queue.pop();
        }
        lv++;
    }

    return lv;
}

// Function to print all non-root nodes that don't have a sibling 
void BST::singles(NodeT *r) { 
    if (r == nullptr) 
      return; 
  
    if (r->getLeft() != nullptr && r->getRight() != nullptr) { 
        singles(r->getLeft()); 
        singles(r->getRight()); 
    } 
    else if (r->getRight() != nullptr) { 
        cout << r->getRight()->getData() << " "; 
        singles(r->getRight()); 
    } 
    else if (r->getLeft() != nullptr) { 
        cout << r->getLeft()->getData()<< " "; 
        singles(r->getLeft()); 
    } 
} 

void BST::printSingles() {
    singles(root);
    
    cout << endl;
}