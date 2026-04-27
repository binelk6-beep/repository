#include <iostream>
using namespace std;
const int maxsize = 100;
struct command {
	int data;
	char src;
	char aux;
	char dest;
	int x;
};
class commands {
private:
	command list[maxsize];
	int top;
public:
	commands() :top(-1) {}
	void push(command task) {
		list[++top] = task;
	}
	void pop() {
		top--;
	}
	command t() {
		return list[top];
	}
	bool empty() {
		return top == -1;
	}
};
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
};
class hanoi {
private:
	int step = 0;
public:
	void solve(int n) {
		commands tasks; mystack pillar[3];
		tasks.push({ n,'A','B','C',1 });
		while (!tasks.empty()) {
			command cur = tasks.t();
			tasks.pop();
			if (cur.data == 1) {
				step++;
				cout << step << ":" << cur.x <<" "<< cur.src << " "<< cur.dest << endl;
			}
			else {
				tasks.push({ cur.data - 1,cur.aux,cur.src,cur.dest,1 });
				tasks.push({ 1,cur.src,cur.aux,cur.dest,cur.data});
				tasks.push({ cur.data - 1,cur.src,cur.dest,cur.aux,1});
			}
		}
	}
};
int main() {
	int n; cin >> n;
	hanoi hanoitower;
	hanoitower.solve(n);
}