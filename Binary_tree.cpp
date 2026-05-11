#include <iostream> 
#include <string>
using namespace std;
struct treenode {
	char name; treenode* lchild, * rchild;
	treenode(char name) :name(name), lchild(nullptr), rchild(nullptr) {}
};
class binary_tree_f {
private:
	int index = 0;
	treenode* root = nullptr;
public:
	treenode* create(int& index, string& s) {
		if ( index >= s.length() || s[index] == '#') {
			index++;
			return nullptr;
	    }
		treenode* root = new treenode(s[index++]);
		root->lchild = create(index, s);
		root->rchild = create(index, s);
		return root;
	}
	void pretaversal(treenode* root) {
		if (!root)
			return;
		cout << root->name;
		pretaversal(root->lchild);
		pretaversal(root->rchild);
	}
	void intaversal(treenode* root) {
		if (!root)
			return;
		intaversal(root->lchild);
		cout << root->name;
		intaversal(root->rchild);
	}
	void posttaversal(treenode* root) {
		if (!root)
			return;
		posttaversal(root->lchild);
		posttaversal(root->rchild);
		cout << root->name;
	}
	treenode* creation(string& s) {
		treenode* root = create(index, s);
		index=0;//重置index
		return root;
	}
	void read_me() {
		cout << "creation用于输入str,返回对应的root" <<endl;
	}
	void pretav(treenode* root) {
		pretaversal(root);
		cout << endl;
	}
	void intav(treenode* root) {
		intaversal(root);
		cout << endl;
	}
	void posttav(treenode* root) {
		posttaversal(root);
		cout << endl;
	}

};
int main() {
	string s; cout << "输入正序遍历的二叉树的str" << endl; cin >> s;
	class binary_tree_f f;
	treenode* root = f.creation(s); //输入str，创建根节点
	f.pretav(root); f.intav(root); f.posttav(root);
}