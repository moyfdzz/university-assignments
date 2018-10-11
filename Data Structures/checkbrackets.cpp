#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Bracket {
	int pos;
	char brack;

	Bracket(int p, char b) {
		pos = p;
		brack = b;
	}
};

bool checkIfOpenBracket(char codeB) {
	switch(codeB) {
		case '(':
			return true;

			break;
		case '{':
			return true;

			break;
		
		case '[':
			return true;

			break;
	}

	return false;
}

bool checkIfClosedBracket(char codeB) {
	switch(codeB) {
		case ')':
			return true;

			break;
		
		case '}':
			return true;

			break;
		
		case ']':
			return true;

			break;
	}

	return false;
}

bool searchPair(char codeB, stack<Bracket> stack) {
	char stackB = stack.top().brack;

	return ((codeB == ')' && stackB == '(') || (codeB == '}' && stackB == '{') || (codeB == ']' && stackB == '['));
}

int main() {
	stack<Bracket> stack;
	string code;

	getline(cin, code);

	for (int i = 0; i < code.length(); i++) {
		int pos = i + 1;

		if (checkIfOpenBracket(code[i])) {
			Bracket bracket(i + 1, code[i]);

			stack.push(bracket);
		}
		else if (checkIfClosedBracket(code[i])) {
			if (stack.empty() || !searchPair(code[i], stack)) {
				cout << pos << endl;

				return 0;
			}
			
			stack.pop();
		}
	}

	if (!stack.empty()) {
		cout << stack.top().pos << endl;

		return 0;
	}

	cout << "Success" << endl;

	return 0;
}