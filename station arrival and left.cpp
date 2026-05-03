#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class station_arrival_and_left {
private:
	struct car_with_station {
		char name;
		int arrival_time;
		car_with_station(char name, int arrival_time) : name(name), arrival_time(arrival_time) {}
	};
	stack<car_with_station> station;
	stack<car_with_station> temp_stack;
	queue<car_with_station> waiting_lane;
	int capacity; 
	int per_pay_per_time;
	
public:
	station_arrival_and_left() {}				
	station_arrival_and_left(int capacity, int per_pay_per_time) : capacity(capacity), per_pay_per_time(per_pay_per_time) {}
	
	void read_me() {
		cout << "该类初始化的第一个参数是capacity,第二个是per_pay_per_time" << endl;
	}
	
	void car_arrival() {
		char name; int arrival_time; 
		cout << "输入新来的车的名字和到达时刻的时间" << endl;
		cin >> name >> arrival_time; 
		car_with_station newcar(name, arrival_time);
		
		if (station.size() == capacity) { // 停车场满了,去候车道
			waiting_lane.push(newcar);
		}
		else {
			station.push(newcar);
		}
	}
	
	void car_left() {
		char name; int left_time; 
		cout << "请输入要出的车的名字和此时的时间" << endl;
		cin >> name >> left_time;
		int found = 0;
		
		while (!station.empty()) {
			car_with_station cur = station.top();
			if (cur.name == name) {
				found = 1; 
				station.pop(); 
				int time = left_time - cur.arrival_time;
				int payment = time * per_pay_per_time;
				cout << "车辆" << name << "出station" << " " << "payment:" << payment << endl;  
				
				while (!temp_stack.empty()) {
					station.push(temp_stack.top());
					temp_stack.pop();
				} // 把temp_stack的车倒回station的stack
				break;
			}
			temp_stack.push(cur);
			station.pop();
		}
		
		if (found == 0) {
			cout << "未找到要找的车" << endl;
			while (!temp_stack.empty()) {
				station.push(temp_stack.top());
				temp_stack.pop();
			}
		}
		
		if (!waiting_lane.empty() && station.size() < capacity) { // waiting_lane有车，且车站有空位入station
			station.push(waiting_lane.front());
			waiting_lane.pop();
		}
	}
	
	void running() {
		while (1) {
			string op; 
			cout << "输入要进行的操作:arrival left exit" << endl;
			cin >> op;
			if (op == "arrival") {
				car_arrival();
			}
			else if (op == "left") {
				car_left();
			}
			else if (op == "exit")                     
				break;
			else
				cout << "输入的op错误" << endl;
		}
	}
};
int main() {
	int capacity, per_pay_per_time;
	cout << "输入停车场的容量和停车的单价" << endl;
	cin >> capacity >> per_pay_per_time;
	station_arrival_and_left station(capacity, per_pay_per_time);
	station.running();
	return 0;
}
