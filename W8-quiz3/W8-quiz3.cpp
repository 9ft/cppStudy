//下面程序的输出结果是：
//A::Print: 1
//B::Print: 2
//B::Print: 3
//请填空：
#include <list>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

template<class T>
void PrintAll(const T & c) {
	typename T::const_iterator i;
	for (i = c.begin(); i != c.end(); ++i)
		(*i)->Print(); //填空
}
class A {
protected:
	int nVal;
public:
	A(int i) :
			nVal(i) {
	}
	virtual void Print() {
		cout << "A::Print: " << nVal << endl;
	}
};
class B: public A {
public:
	B(int i) :
			A(i) {
	}
	void Print() {
		cout << "B::Print: " << nVal << endl;
	}
};
int main() {
	list<A*> v; //填空
	v.push_back(new A(1));
	v.push_back(new B(2));
	v.push_back(new B(3));
	PrintAll(v);
	return 0;
}
