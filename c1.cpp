#include <iostream>
using namespace std;
const int maxsize = 100;
class mystack {
private:
	int list[maxsize];
	int top;
public:
	mystack() :top(-1) {}
	void push() {
		int val; cin >> val;
		list[++top] = val;
	}
	void pop() {
		top--;
	}
	int t() {
		return list[top];
	}
	void empty() {
		if (top == -1)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
	void push_lots(){
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			push();
		}
	}
	void pop_lots() {
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			pop();
		}
	}
	void taversal() {
		for (int i = 0; i < top + 1; i++) {
			cout << list[i] << " ";
		}
	}
};
int main() {
	mystack Mystack;
	Mystack.push_lots();
	Mystack.pop_lots();
	Mystack.empty();
	cout << Mystack.t() << endl;
	Mystack.taversal();
}