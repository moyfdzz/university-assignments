#include <iostream>
#include <vector>
using namespace std;

class Priority {
    public:
        Priority();
        Priority(bool p);
        void push(int data);
        void pop();
        int top();
        int size();
        bool empty();
        void print();

    private:
        vector<int> vectorHeap;
        bool boolPriority;
};

void Priority::print() {
    for (int i = 1; i < vectorHeap.size(); i++) {
        cout << vectorHeap[i] << " ";
    }
}

Priority::Priority() {
    vectorHeap.push_back(1234);
    boolPriority = true;
}

Priority::Priority(bool p) {
    vectorHeap.push_back(1234);
    boolPriority = p;
}

void Priority::push(int data) {
    vectorHeap.push_back(data);

    int curr = vectorHeap.size() - 1;

    if (boolPriority) {
        while (curr > 1 && vectorHeap[curr / 2] < vectorHeap[curr]) {
            int temp = vectorHeap[curr / 2];

            vectorHeap[curr / 2] = vectorHeap[curr];
            vectorHeap[curr] = temp;

            curr = curr / 2;
        }
    }
    else {
        while (curr > 1 && vectorHeap[curr / 2] > vectorHeap[curr]) {
            int temp = vectorHeap[curr / 2];

            vectorHeap[curr / 2] = vectorHeap[curr];
            vectorHeap[curr] = temp;

            curr = curr / 2;
        }
    }
}

void Priority::pop() {
    if (!empty()) {
        int temp = vectorHeap[1];

        vectorHeap[1] = vectorHeap[vectorHeap.size() - 1];
        vectorHeap[vectorHeap.size() - 1] = temp;

        vectorHeap.resize(vectorHeap.size() - 1);

        int curr = vectorHeap[1];
        int aux = curr;
        int hijos = 2 * curr;

        if (boolPriority) {
            
        }
        else {

        }
    }
}

int Priority::top() {
    return vectorHeap[1];
}

int Priority::size() {
    return vectorHeap.size() - 1;
}

bool Priority::empty() {
    return vectorHeap.size() == 1;
}