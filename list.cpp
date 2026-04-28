#include <iostream>
#include <list>
int main() {
	std::list<int> my_list;
	my_list.push_back(3);
	my_list.push_front(2);
	my_list.push_front(1);
	my_list.push_front(0);
	for (const int & val : my_list)
		std::cout << val << std::endl;
	}