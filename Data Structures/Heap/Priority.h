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
        bool biggestChildNode(int curr);
        bool smallestChildNode(int curr);
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

bool Priority::biggestChildNode(int curr) {
    if(curr * 2 + 1 > vectorHeap.size() - 1){
        return true;
    }
    else{
        return(vectorHeap[curr * 2] > vectorHeap[curr * 2 + 1]) ? true : false;
    }
}

bool Priority::smallestChildNode(int curr) {
    if(curr * 2 + 1 > vectorHeap.size () - 1) {
        return true;
    }
    else {
        return(vectorHeap[curr * 2] < vectorHeap[curr * 2 + 1]) ? true : false;
    }
}

void Priority::pop(){
 
 if(vectorHeap.size() > 1) {
    
    vectorHeap[1] = vectorHeap.back();
    vectorHeap.pop_back();

    int curr = 1;
    int children = curr * 2;
    int aux, biggest, smallest;
    bool check = true;

    if(boolPriority) {
        while(children <= vectorHeap.size() - 1 && check) {
            biggest = biggestChildNode(curr) ? curr * 2 : curr * 2 + 1;
            
            if(vectorHeap[curr] < vectorHeap[biggest]) {
                aux = vectorHeap[curr];
                vectorHeap[curr] = vectorHeap[biggest];
                vectorHeap[biggest] = aux;
                curr = biggest;
                children = curr * 2;
            } 
            else {
                check = false;
            }
        }
    } 
    else{
        while(children <= vectorHeap.size() - 1 && check) {
            smallest = smallestChildNode(curr) ? curr * 2 : curr * 2 + 1;
            
            if(vectorHeap[curr] > vectorHeap[smallest]) {
                aux = vectorHeap[curr];
                vectorHeap[curr] = vectorHeap[smallest];
                vectorHeap[smallest] = aux;
                curr = smallest;
                children = curr * 2;
            } 
            else {
                check = false;
            }
        }
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