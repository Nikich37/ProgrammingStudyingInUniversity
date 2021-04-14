#include <iostream>
#include <string>
#include <stack>
using namespace std;

string MathExp;
stack <char> steck;

void EnterMathExp() {
	cout << "Enter a mathematical expression: ";
	cin >> MathExp;
}

void ReadAndOutMathExp() {
	for (int i = 0; i < MathExp.size(); i++) {
		if (MathExp[i] == '0' || MathExp[i] == '1' || MathExp[i] == '2' || MathExp[i] == '3' ||
			MathExp[i] == '4' || MathExp[i] == '5' || MathExp[i] == '6' || MathExp[i] == '7' ||
			MathExp[i] == '8' || MathExp[i] == '9' || MathExp[i] == ' ')
			cout << MathExp[i];
		if (MathExp[i] == '(')
			steck.push(MathExp[i]);
		if (MathExp[i] == ')') {
			while (steck.top() != '(') {
				if (steck.empty() == true) {
					cout << "Error";
					return;
				}
				cout << steck.top();
				steck.pop();
			}
			steck.pop();
		}
		if (MathExp[i] == '+' || MathExp[i] == '-') {
			while (steck.empty() == false && (steck.top() == '-' || steck.top() == '+' ||
				steck.top() == '*' || steck.top() == '/')) {
				cout << steck.top();
				steck.pop();
			}
			steck.push(MathExp[i]);
		}
		if (MathExp[i] == '*' || MathExp[i] == '/' ) {
			while (steck.empty() == false && 
				(steck.top() == '*' || steck.top() == '/')) {
				cout << steck.top();
				steck.pop();
			}
			steck.push(MathExp[i]);
		}
		if (MathExp[i] == '^')
			steck.push(MathExp[i]);
	}
	while (steck.empty() != true) {
		cout << steck.top();
		steck.pop();
	}
}

int main() {
	EnterMathExp();
	ReadAndOutMathExp();
	return 0;
}