#include<stack>
#include<iostream>
#include<string>
using namespace std;
class calculation{
private:
	stack<int> numstack;
	stack<char> opstack;
public:
	int minest_calculation(int a,int b,char op){
		if(op == '-')
			return a-b;
		else if(op == '+')
			return a+b;
		else if(op == '*')
			return a*b;
		else if(op == '/')
			return a/b;
		else
			return 0;
	}//输入参数 1：左操作数 2：右操作数 3：运算符
	int priority(char op){
		if(op == '(')
			return 0;
		else if(op =='-' || op == '+')
			return 1;
		else 
			return 2;
	}//计算运算符的优先级,(:0
	void stack_calculation(stack<int> &numstack,stack<char> &opstack){
		int b = numstack.top();numstack.pop();//先取的是右操作数
		int a = numstack.top();numstack.pop();
		numstack.push(minest_calculation(a,b,opstack.top()));opstack.pop();
	}//栈计算，取numstack的两个数，opstack取一个运算符，把计算结果入numstack
	int str_calculation(string &str){
		for(int i=0;i<str.length();i++){//基本入栈
			if(isdigit(str[i])){
				int val = 0;
				while(isdigit(str[i])){
					val = val*10 +(str[i]-'0');
					i++;
				}//从左到右读出这个数入栈
				numstack.push(val);
				i--;
			}
			else if(str[i]=='('){
				opstack.push('(');
			}
			else if(str[i]==')'){//把括号里的算尽
				while(opstack.top()!='('){
					stack_calculation(numstack,opstack);
				}
				opstack.pop();//把'('出栈
			}
			else{
				while(!opstack.empty() && priority(opstack.top()) >= priority(str[i])){
					stack_calculation(numstack,opstack);
				}
				opstack.push(str[i]);
			}
		}
		while(!opstack.empty()){
			stack_calculation(numstack,opstack);
		}
		return numstack.top();
	} 
};
int main(){
	string str;cout << "输入运算表达式"<<endl;cin >> str;
	calculation solution;
	cout << solution.str_calculation(str) << endl;
}
