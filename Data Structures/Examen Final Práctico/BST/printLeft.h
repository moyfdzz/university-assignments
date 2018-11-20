void BST::printLeft() {
    int BSTHeight = altura(root);
    int nodeData = root->getData();
    int counter = 0;

    queue<NodeT *> nodesQueue;
    nodesQueue.push(root);
    NodeT *curr;

    while (!nodesQueue.empty()) {
        curr = nodesQueue.front();
        nodesQueue.pop();

        if(curr->getData() <= nodeData && counter < BSTHeight) {
            cout << curr->getData() << " ";
            
            counter++;
        }
         
        if (curr->getLeft() != nullptr) {
            nodesQueue.push(curr->getLeft());
        }

        if (curr->getRight() != nullptr) {
            nodesQueue.push(curr->getRight());
        }
    }

    while (curr -> getRight() != nullptr) {
        curr = curr->getRight();
    }  

    cout << curr->getData() << endl;
}