#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* &prev, ListNode* &node) {
    ListNode* aux;

    prev->next = node->next;
    aux = node;
    node = node->next;
    delete aux;
}

ListNode* deleteUnique(ListNode* head) {
    if (head == nullptr) {
        return 0;
    }
    
    if (head->next != nullptr) {
        delete head;
    }

    ListNode* currNode = head;
    ListNode* nextNode = currNode;
    ListNode* aux;

    while (currNode->next != nullptr) {
        nextNode = nextNode->next;

        if (currNode == head) {
            if (currNode->val != nextNode->val && nextNode->val != nextNode->next->val) {
                aux = head;
                head = head->next;
                delete aux;
            }             
        } 
        else if (currN)
        
        if (currNode != head && currNode->val != nextNode->val && nextNode->val != nextNode->next->val) {

        }

        // if (currNode->val != nextNode->val) {
        //     if (nextNode->next != nullptr) {
        //         if (nextNode->val != nextNode->next->val) {
        //             deleteNode(head, currNode, nextNode);
        //         }
        //     }
        // }
        // else {
        //     currNode = nextNode;
        // }
    }

    return head;
}

int main() {


    return 0;
}