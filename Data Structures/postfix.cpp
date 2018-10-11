#include <iostream>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

void performPostfix(const string d, stack<int>& s1, queue<int>& q1, priority_queue<int, vector<int>, greater<int> >& pq1) {
    int xS, xQ, xPQ, yS, yQ, yPQ, resultS, resultQ, resultPQ;

    xS = s1.top(); // x stack
    s1.pop();

    yS = s1.top(); // y stack
    s1.pop();

    xQ = q1.front(); // x queue
    q1.pop();

    yQ = q1.front(); // y queue
    q1.pop();

    xPQ = pq1.top(); // x priority queue
    pq1.pop();

    yPQ = pq1.top(); // y priority queue
    pq1.pop();

    if(d == "-") {
        resultS = yS - xS;
        resultQ = yQ - xQ;
        resultPQ = yPQ - xPQ;
    }
    else if(d == "+") {
        resultS = yS + xS;
        resultQ = yQ + xQ;
        resultPQ = yPQ + xPQ;
    }
    else if(d == "*") {
        resultS = yS * xS;
        resultQ = yQ * xQ;
        resultPQ = yPQ * xPQ;
    }

    s1.push(resultS);
    q1.push(resultQ);
    pq1.push(resultPQ);
}

int main () {
    string d, data;
 
    getline(cin, data);

    while (data != "#"){
        stack<int> s1;
        queue<int> q1;
        priority_queue<int, vector<int>, greater<int> > pq1;

        stringstream ss;

        ss << data;

        while (ss >> d) {
            int num;

            if(istringstream(d) >> num) { //si es un número lo mete al contenedor
                s1.push(num);
                q1.push(num);
                pq1.push(num);
            }
            else {
                performPostfix(d, s1, q1, pq1);
            }
        }

        cout << s1.top() << " " << q1.front() << " " << pq1.top() << endl;

        getline(cin, data);	
    }

    return 0;
}