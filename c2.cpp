#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
struct treenode {
	char name;
	treenode* left,* right;
	treenode(char name):name(name),left(nullptr),right(nullptr){}
};
treenode* create_tree(const string& str, int& index) {
	if (str[index] == '#' || index >= str.length()) {
		index++;
		return nullptr;
	}
	treenode* root = new treenode(str[index++]);
	root->left = create_tree(str, index);
	root->right = create_tree(str, index);
	return root;
}
queue<treenode*> Q;
void level_taversal(treenode* root) {
	if (!root)
		return;
	Q.push(root);
	while (!Q.empty()) {
		treenode
		* cur = Q.front();Q.pop();//取出队首
		cout << cur->name;
		if (cur->left) {
			Q.push(cur->left);
		}
		if (cur->right) {
			Q.push(cur->right);
		}
	}
	cout << endl;
}
int main() {
	string str; cout << "输入正序遍历的二叉树" << endl; cin >> str;
	int index = 0;
	treenode* root = create_tree(str, index);
	level_taversal(root);
}