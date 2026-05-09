#include <iostream>
#include <climits>
#include <string> 
using namespace std;
struct node {
	int parent_idx, lchild_idx, rchild_idx, weigh;
	node() :parent_idx(-1), lchild_idx(-1), rchild_idx(-1), weigh(0) {}
};

class haffman {
private:
public:
	node* init(int &count) {
		int n; cout << "输入要编码的字符的个数" << endl; cin >> n;
		count = n;
		node* arr = new node[2 * n - 1];//创建数组，大小为2*n-1;
		cout << "分别输入n个字符的权重" << endl;
		for (int i = 0; i < n; i++) {
			int weigh; cin >> weigh;
			arr[i].weigh = weigh;
		}
		for (int i = n; i < 2 * n - 1; i++) {
			int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1, idx2 = -1;
			for (int j = 0; j < i; j++) {
				if (arr[j].parent_idx == -1) {
					if (arr[j].weigh < min1) {
						min2 = min1; idx2 = idx1;
						min1 = arr[j].weigh; idx1 = j;
					}
					else if (arr[j].weigh < min2) {
						min2 = arr[j].weigh; idx2 = j;
					}
				}
			}
			arr[i].weigh = min1 + min2;
			arr[i].lchild_idx = idx1; arr[i].rchild_idx = idx2;
			arr[idx1].parent_idx = i; arr[idx2].parent_idx = i;
		}
		return arr;
	}
	void coding_printing(int n,node* &arr) {
		for (int i = 0; i < n; i++) {
			string code = "";
			int cur = i;
			int p = arr[cur].parent_idx;
			cout << "权重:" << arr[cur].weigh << " " << "编码:" << " ";
			while (p!=-1) {
				if (arr[p].lchild_idx==cur) {
					code += '0';
				}
				else
					code += '1';
				cur = p; p = arr[p].parent_idx;
			}
			cout <<code <<  endl;
		}
	}
	void destroy(node* arr) {
		delete[] arr;
	}
};
int main() {
	class haffman haffman_coding; int n;
	node* arr = haffman_coding.init(n);
	haffman_coding.coding_printing(n, arr);
	haffman_coding.destroy(arr);
}