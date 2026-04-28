#include <iostream>
#include <stack>
#include <string>
#include "calculation.h"
using namespace std;
int main(){
	stack<int> numstack; stack<char> opstack;
	string str; cout << "输入表达式" << endl; cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			int val = 0;
			while (isdigit(str[i])) {
				val = val * 10 + (str[i] - '0');
				i++;
			}
			numstack.push(val);i--;
		}
		else if (str[i] == '(') {
			opstack.push('(');
		}
		else if (str[i] == ')') {
			while (opstack.top() != '(') {
				int b = numstack.top(); numstack.pop();
				int a = numstack.top(); numstack.pop();
				numstack.push(calculate(a, b, opstack.top()));
				opstack.pop();
			}
			opstack.pop();
		}
		else {
			while (!opstack.empty() && priority(opstack.top()) >= priority(str[i])) {
				int b = numstack.top(); numstack.pop();
				int a = numstack.top(); numstack.pop();
				numstack.push(calculate(a, b, opstack.top()));
				opstack.pop();
			}
			opstack.push(str[i]);
		}
	}
	while (!opstack.empty()) {
		int b = numstack.top(); numstack.pop();
		int a = numstack.top(); numstack.pop();
		numstack.push(calculate(a, b, opstack.top()));
		opstack.pop();
	}
	cout << numstack.top();
}