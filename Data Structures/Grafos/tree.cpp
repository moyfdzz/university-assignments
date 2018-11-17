#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void leeListAdj(vector<vector<int> > &listAdj, int e){
	int a, b;
	for (int i=0; i<e; i++){
		cin >> a >> b;
		listAdj[a-1].push_back(b-1);
	}
}

void printListAdj(vector<vector<int> > &listAdj, int e){
	for (int i=0; i<listAdj.size(); i++){
		cout << i << " ";
		for (int j=0; j< listAdj[i].size(); j++){
			cout << " - " << listAdj[i][j];
		}
		cout << endl;
	}
}

bool isTree(vector<vector<int> > &listAdj, int e){
    if (e != listAdj.size() - 1) {
        return false;
    }

    vector<bool> visit(listAdj.size(), false);
    visit[0] = true;
    stack<int> miPila;
    miPila.push(0);
    int dato, contVisit = 1;

    while (!miPila.empty()) {
        dato = miPila.top();
        cout << dato << endl;
        miPila.pop();

        if (visit[dato]) {
            return false;
        }

        for (int i = listAdj[dato].size() - 1; i >= 0; i--) {
            if (visit[listAdj[dato][i]]) {
                return false;
            }
            
            visit[listAdj[dato][i]] = true;
            miPila.push(visit[listAdj[dato][i]]);
            contVisit++;
        }
    }

    return contVisit == listAdj.size();
}

int main(){

	int v, e;
	cin >> v >> e;
	vector<vector<int> > listAdj(v);
	leeListAdj(listAdj, e);
//	printListAdj(listAdj, v);
	cout << (isTree(listAdj, v)? "YES" : "NO" << endl;
	return 0;
}