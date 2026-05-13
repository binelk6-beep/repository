#include <iostream>
#include <stack>
#include <queue>
class station_management{
private:
	struct car{
		int arrival_time;
		char name;
		car(int arrival_time,char name):name(name),arrival_time(arrival_time){}
	};
	std::stack<car> station,temp_stack;
	std::queue<car> waitting_line;
	int capacity;
	int pay_pertime;
public:
	station_management(int capacity,int pay_pertime):capacity(capacity),pay_pertime(pay_pertime){}
	void arrival(){
		int arrival_time;char name;std::cout <<"输入新来的车的name和到达时间"<<std::endl;std::cin >> name >> arrival_time;
		car newcar(arrival_time,name);
		if(station.size()==capacity){//如果停车场满了
			waitting_line.push(newcar);
			std::cout << "车辆" << newcar.name << "have parked at waiting line" << std::endl;
		}
		else{
			station.push(newcar);
			std::cout <<"车辆" << newcar.name << "have parked at station" << std::endl;
		}
	}
	void left(){
		char name;int left_time;std::cout << "输入要出栈的车辆name和此时的时间" <<std::endl;std::cin >> name >> left_time;
		int found=0;
		while(!station.empty()){
			if(station.top().name==name){
				int time = left_time - station.top().arrival_time;found =1;
				int payment = pay_pertime*time;
				station.pop();
				std::cout << "车辆" << name << "has left. " << "the payment is " << payment << std::endl;
				while(!temp_stack.empty()){
					station.push(temp_stack.top());temp_stack.pop();
				}
				break;
			}
			else{
				temp_stack.push(station.top());station.pop();
			}
		}
		if(!found){
			std::cout << "the car is not be found" << std::endl;
			while(!temp_stack.empty()){
				station.push(temp_stack.top());temp_stack.pop();
			}
			return;
		}//没找到,把车塞回去
		if(!waitting_line.empty()){
			station.push(waitting_line.front());
			std::cout << "the car" << waitting_line.front().name << "has enter the station" << std::endl;
			waitting_line.pop();
		}//车left以后waitting_line有车，车入station
	}
};
int main(){
	int capacity;int pay_pertime;std::cout << "输入station的容量和停车单价"<< std::endl;std::cin >>capacity >> pay_pertime;
	station_management  s1(capacity,pay_pertime);
	while(1){
		std::cout << "please input your operation: a.car_arival;b.car_left" <<std::endl;
		char op; std::cin >>op;
		if(op == 'a')
			s1.arrival();
		else if(op == 'b')
			s1.left();
		else 
			std:: cout << "input error" << std::endl;
	}
}
