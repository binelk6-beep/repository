#include <iostream>
#include <string>
using namespace std;
struct node {
	char name;
	node* lchild, * rchild;
	node() :name('0'), lchild(nullptr), rchild(nullptr) {}
};
class binary_tree {
private:
public:
	void create(node* &root) {
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
int main() {
	node* root = new node;
	class binary_tree mytree;
	mytree.create(root);
	mytree.pre_taversal(root); cout << endl;
	mytree.in_taversal(root); cout << endl;
	mytree.post_taversal(root);
}