#include <iostream>
#include "Priority.h"
using namespace std;

int main() {
  
  Priority pq;
  Priority pq2(false);
  Priority pq3;

  pq.push(1);
  pq.push(15);
  pq.push(218);
  pq.push(35);
  pq.push(54);
  pq.push(69);
  pq.push(12);
  pq.push(22);
  pq.push(24);
  pq.push(28);

  cout << pq.size() << endl;
  cout << pq.top() << endl;

  pq2.push(1);
  pq2.push(15);
  pq2.push(218);
  pq2.push(35);
  pq2.push(54);
  pq2.push(69);
  pq2.push(12);
  pq2.push(22);
  pq2.push(24);
  pq2.push(28);

  cout << pq2.size() << endl;
  cout << pq2.top() << endl;

  cout << endl;
  cout << endl;

  cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();
    cout << pq.top() << endl;
  pq.pop();

     cout << pq.top() << endl;
  pq.pop();
  cout <<pq.size() << endl;
  cout << pq.empty() << endl;

  cout << endl;
  cout << endl;

    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
    cout << pq2.top() << endl;
  pq2.pop();
     cout << pq2.top() << endl;
  pq2.pop();
    cout <<pq.size() << endl;
  cout << pq.empty() << endl;

  





  return 0;
}