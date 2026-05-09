#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct node {
	char name;
	node* lchild, * rchild;
	node() :name('0'), lchild(nullptr), rchild(nullptr) {}
};
class binary_tree {
private:
public:
	void create(node*& root) {
		char ch; cin >> ch;
		if (ch == '#') {
			root = nullptr;
			return;
		}
		root = new node;
		root->name = ch;
		create(root->lchild);
		create(root->rchild);
	}
	void pre_taversal(node* root) {
		if (!root)
			return;
		cout << root->name;
		pre_taversal(root->lchild);
		pre_taversal(root->rchild);
	}
	void in_taversal(node* root) {
		if (!root)
			return;
		in_taversal(root->lchild);
		cout << root->name;
		in_taversal(root->rchild);
	}
	void post_taversal(node* root) {
		if (!root)
			return;
		post_taversal(root->lchild);
		post_taversal(root->rchild);
		cout << root->name;
	}
};
class taversal_floor {
private:
	queue<node*>  Queue;
public:
	void running(node* root) {
		Queue.push(root);
		while (!Queue.empty()) {
			node* cur = Queue.front(); Queue.pop();
			
			if(cur->lchild)
				Queue.push(cur->lchild);
			if(cur->rchild)
				Queue.push(cur->rchild);
			cout << cur->name;
		}
	}
};
int main() {
	node* root = nullptr;
	class binary_tree mytree;
	mytree.create(root);
	class taversal_floor floor;
	floor.running(root);
}