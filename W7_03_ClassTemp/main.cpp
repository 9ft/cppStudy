#include <iostream>
using namespace std;

template<class T1, class T2>
class Pair {
public:
	T1 key;
	T2 value;
	Pair(T1 k, T2 v) :
			key(k), value(v) {
	}
	bool operator <(const Pair<T1, T2> &p) const;
};
template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p) const {
	return key < p.key;
}

//类模板的类型参数和函数模板的类型参数是不能一致的
template<class T>
class A {
public:
	template<class T2> //成员函数模板
	void Func(T2 t) {
		cout << t;
	}
};

//类模板与非类型参数
template<class T, int size>
class CArray {
	T array[size];
public:
	void Print() {
		for (int i = 0; i < size; ++i) {
			cout << array[i] << endl;
		}
	}
};

//(1)类模板从类模板派生
template<class T1, class T2>
class A1 {
	T1 v1;
	T2 v2;
};
template<class T1, class T2>
class B1: public A1<T2, T1> {
	T1 v3;
	T2 v4;
};
template<class T>
class C1: public B1<T, T> {
	T v5;
};

//(2)类模板从模板类派生
template<class T1, class T2>
class A11 {
	T1 v1;
	T2 v2;
};
template<class T>
class B11: public A11<int, double> {
	T v;
};

//(3)类模板从普通类派生

int main() {
	Pair<string, int> student("Tom", 19);
	cout << student.key << " " << student.value;

	A<int> a;
	a.Func("K");

	//参数不同，为不同的两个类
	//CArray<double, 40> a2;
	//CArray<int, 50> a3;

	B11<char> obj1;

	return 0;
}
