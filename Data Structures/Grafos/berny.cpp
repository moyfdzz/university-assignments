#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    int age;
    string son;
};

void fillGraph(unordered_map<string, vector<Node>> &graph, int n) {
    string father, son;
    int age;
    Node aux;

    vector<Node> Nodes(0);

    for (int i = 0; i < n; i++) {
        cin >> father >> son >> age;

        if (graph.find(father) == graph.end()) {
            aux.age = age;
            aux.son = son;

            Nodes.push_back(aux);

            graph.insert(pair<string, vector<Node>> (father, Nodes));
        }
        else {
            
        }
    }
}

int main () {
    int n;

    cin >> n;

    unordered_map<string, vector<Node>> graph;
    fillGraph(graph, n);

    return 0;
}