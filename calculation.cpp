#include <iostream>
#include <string>
using namespace std;
const int maxsize = 100;
class mystack {
private:
	int list[maxsize];
	int top;
public:
	mystack() : top(-1) {}
	void push(int val) {
		list[++top] = val;
	}
	void pop() {
		top--;
	}
	int t() {
		return list[top];
	}
	bool empty() {
		return top == -1;
	}
};
class chstack {
public:
	char list[maxsize];
	int top;
public:
	chstack() :top(-1) {}
	void push(char val) {
		list[++top] = val;
	}
	void pop() {
		top--;
	}
	char t() {
		return list[top];
	}
	bool empty() {
		return top == -1;
	}
};
int priority(char op) {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else
		return 0;
}
int calculate(int a, int b, char op) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
	else if (op == '/')
		return a / b;
	else
		return 0;
}
int main() {
	string s; cin >> s;
	mystack numstack; chstack opstack;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])){
			int val=0;
			while (isdigit(s[i])) {
				val=val*10+(s[i]-'0');
				i++;
			}
			i--;
			numstack.push(val);
		}
		else if (s[i] == '(') {
			opstack.push(s[i]);
		}
		else if (s[i] == ')') {
			while (opstack.t()!='(') {
				int b = numstack.t(); numstack.pop();
				int a = numstack.t(); numstack.pop();
				numstack.push(calculate(a, b, opstack.t()));
				opstack.pop();
			}
			opstack.pop();
		}
		else {
			while (!opstack.empty() && priority(opstack.t()) >= priority(s[i])) {
				int b = numstack.t(); numstack.pop();
				int a = numstack.t(); numstack.pop();
				numstack.push(calculate(a, b, opstack.t()));
				opstack.pop();
			}
			opstack.push(s[i]);
		}
	}
	while (!opstack.empty()) {
		int b = numstack.t(); numstack.pop();
		int a = numstack.t(); numstack.pop();
		numstack.push(calculate(a, b, opstack.t()));
		opstack.pop();
	}
	cout << numstack.t();
}
