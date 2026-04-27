#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
struct treenode {
	char name;
	treenode* l_child, * r_child;
	treenode():name(0),l_child(nullptr),r_child(nullptr){}
	treenode(char name):name(name),l_child(nullptr),r_child(nullptr){}
};
class Binary_tree {//写个类，要求传入一个参数，生成的类包含了对应的树形结构
private:
	treenode* root;
	int index = 0; //正序遍历输入并且那个#表示空节点
public:
	Binary_tree(string str) {
		root = create_tree(str);
	}
	treenode* create_tree(const string& str) {
		if (str[index] == '#' || index >= str.length()) {
			index++;
			return nullptr;
		}
		treenode* root = new treenode(str[index++]);
		root->l_child = create_tree(str);
		root->r_child = create_tree(str);
		return root;
	}
	void preordered_print(treenode* root) {
		if (!root)
			return;
		cout << root->name;
		preordered_print(root->l_child);
		preordered_print(root->r_child);
	}
	void inordered_print(treenode* root) {
		if (!root)
			return;
		inordered_print(root->l_child);
		cout << root->name;
		inordered_print(root->r_child);
	}
	void postordered_print(treenode* root) {
		if (!root)
			return;
		postordered_print(root->l_child);
		postordered_print(root->r_child);
		cout << root->name;
	}
	void level_print(treenode* root) {
		queue<treenode*> Q;
		if (!root)
			return;
		Q.push(root);
		while (!Q.empty()) {
			treenode* cur = Q.front(); Q.pop();
			cout << cur->name;
			if(cur->l_child) {
				Q.push(cur->l_child);
			}
			if (cur->r_child) {
				Q.push(cur->r_child);
			}
		}
	}
	int level_count(treenode* root) {
		if (!root)
			return 0;
		return max(level_count(root->l_child), level_count(root->r_child)) + 1;
	}
	int leaf_count(treenode* root) {
		if (!root)
			return 0;
		if (!root->l_child && !root->r_child)
			return 1;
		return leaf_count(root->l_child) + leaf_count(root->r_child);
	}
	treenode* root_return () {
		return root;
	}
};
int main() {
	string str; cout << "输入正序遍历的字符串"; cin >> str;
	Binary_tree tree(str);
	treenode* root = tree.root_return();		
	tree.preordered_print(root); cout << endl;
	tree.inordered_print(root); cout << endl;
	tree.level_print(root);
}
