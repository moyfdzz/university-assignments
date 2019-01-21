#include <iostream>
#include <string>
using namespace std;

char returnUniqueCharacter(string input) {
    int left = 0, right = input.length() - 1, mid;
    bool odd = ((right - left) % 4 == 0);

    while (true) {
        mid = (left + right) / 2;

        if (left == right)
            return input[mid];

        if(input[mid] == input[mid + 1]) {
            (odd ? left = mid + 2 : right = mid - 1);
        }
        else if (input[mid] == input[mid - 1]) {
            (odd ? right = mid - 2 : left = mid + 1);
        }
        else
            return input[mid];

        odd = ((right - left) % 4 == 0);
    }

    return 'Z';
}

int main() {
    string input;

    cin >> input;

    cout << returnUniqueCharacter(input) << endl;

    return 0;
}