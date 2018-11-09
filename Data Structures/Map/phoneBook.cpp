#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<int, string> phoneBook;

    int n, number;
    string command, name;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;

        if (command == "add") {
            cin >> number >> name;

            if (phoneBook.find(number) != phoneBook.end()) {
                phoneBook.find(number)->second = name;
            }
            else {
                phoneBook.insert(pair<int, string>(number, name));
            }
        }
        else if (command == "del") {
            cin >> number;

            phoneBook.erase(number);
        }
        else if (command == "find") {
            cin >> number;

            if (phoneBook.find(number) != phoneBook.end()) {
                cout << phoneBook.find(number)->second << endl;
            }
            else {
                cout << "not found" << endl;
            }
        }
    }
}