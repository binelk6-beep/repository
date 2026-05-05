#include<iostream>
#include<string>
using namespace std;
struct treenode{
	char name;
	treenode* lchild,*rchild;
	treenode():name('0'),lchild(nullptr),rchild(nullptr){}
	treenode(char name):name(name),lchild(nullptr),rchild(nullptr){}
};
class binarytree{
public:
	void read_me(){
		cout <<"本类本质是二叉树通过正序遍历的字符串的输入,将其转化为cpp里面具体的数据结构的功能类";
	}
	treenode* creation(string &str,int &index){//这个input的str一定是正序遍历的binary_tree;
		if(str[index] == '#' || index >= (int)str.length()){//length()得到的是size_t,及无符号整数
			index++;
			return nullptr;
		}
		treenode* root = new treenode(str[index++]);
		root->lchild = creation(str,index);
		root->rchild = creation(str,index);
		return root;
	}
	void pre_taversal(treenode* root){
		if(!root)
			return;
		cout << root->name;
		pre_taversal(root->lchild);
		pre_taversal(root->rchild);
	}
	void in_taversal(treenode* root){
		if(!root)
			return;
		in_taversal(root->lchild);
		cout << root->name;
		in_taversal(root->rchild);
	}
	void post_taversal(treenode* root){
		if(!root)
			return;
		post_taversal(root->lchild);
		post_taversal(root->rchild);
		cout <<root->name;
	}
};
int main(){
	string str;cin >>str;int index =0;
	class binarytree mytree;
	treenode* root = mytree.creation(str,index);index = 0;
	mytree.pre_taversal(root);cout <<endl;
	mytree.in_taversal(root);		
}
