#include <iostream>
using namespace std;
const int maxsize = 100;
class mystack {
private:
	int list[maxsize];
	int top;
public:
	mystack() :top(-1) {}
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
	void traversal() {
		for (int i = top; i >= 0; i--) {
			cout << list[i];
		}

	}
};

void  ten_to_eight(int number) {
	mystack Mystack;
	while (number) {
		int x = number % 8;
		Mystack.push(x);
		number /= 8;
	}
	Mystack.traversal();
}
int main() {
	int number; cin >> number;
	ten_to_eight(number);
}