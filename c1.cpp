#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct treenode {
	char name;
	treenode* l_child, * r_child;
	treenode(char name):name(name),l_child(nullptr),r_child(nullptr){}
};
treenode* creat_tree(const string &str,int &index) {//用之前一定要初始化index=0
	if (index > str.length() || str[index] == '#') {
		index++;
		return nullptr;
	}
	treenode* root = new treenode(str[index++]);
	root->l_child = creat_tree(str,index);
	root->r_child = creat_tree(str, index);
	return root;
}
void preorder_traversal(treenode* root) {
	if (!root)
		return;
	cout << root->name;
	preorder_traversal(root->l_child);
	preorder_traversal(root->r_child);
}
void inorder_traversal(treenode* root) {
	if (!root)
		return;
	inorder_traversal(root->l_child);
	cout << root->name;
	inorder_traversal(root->r_child);
}
void postordered_taversal(treenode* root) {
	if (!root)
		return;
	postordered_taversal(root->l_child);
	postordered_taversal(root->r_child);
	cout << root->name;
}
int level(treenode* root) {
	if (!root)
		return 0;
	return max(level(root->l_child), level(root->r_child)) + 1;
}
int leaf(treenode* root){
	if (!root)
		return 0;
	if (!root->l_child && !root->r_child)
		return 1;
	return leaf(root->l_child) + leaf(root->r_child);
}
void swap_child(treenode* root) {
	if (!root)
		return;
	swap(root->l_child, root->r_child);
	swap_child(root->l_child);
	swap_child(root->r_child);
}
int main() {
	string str; cout << "输入正序遍历的二插数" << endl; cin >> str;
	int index = 0;
	treenode* root = creat_tree(str, index);
	preorder_traversal(root); cout << " "; inorder_traversal(root); cout << " "; postordered_taversal(root);
	cout << endl;
	cout << leaf(root) << " " <<  level(root) << endl;
	swap_child(root); 
	preorder_traversal(root); cout << " "; inorder_traversal(root); cout << " "; postordered_taversal(root);
}







