#include <iostream>
#include <stack>
using namespace std;
int priority(char op) {
	if (op == '-' || op == '+')
		return 1;
	else if (op == '(')
		return 0;
	else
		return 2;
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
