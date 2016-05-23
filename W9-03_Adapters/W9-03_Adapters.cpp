#include<queue>
#include <iostream>
using namespace std;
int main() {
	priority_queue<double> priorities;
	priorities.push(3.2);
	priorities.push(9.8);
	priorities.push(5.4);
	while (!priorities.empty()) {
		cout << priorities.top() << "";
		priorities.pop();
	}
	//Êä³ö½á¹û: 9.8 5.4 3.2
	return 0;
}
