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
class A1 {
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
class A2 {
	T1 v1;
	T2 v2;
};
template<class T1, class T2>
class B2: public A2<T2, T1> {
	T1 v3;
	T2 v4;
};
template<class T>
class C2: public B2<T, T> {
	T v5;
};

//(2)类模板从模板类派生
template<class T1, class T2>
class A3 {
	T1 v1;
	T2 v2;
};
template<class T>
class B3: public A3<int, double> {
	T v;
};

//(3)类模板从普通类派生
class A4 {
	int v1;
};
template<class T>
class B4: public A4 {
	T v;
};

//(4)普通类从模板类派生
template<class T>
class A5 {
	T v1;
	int n;
};
class B5:public A5<int> {
	double v;
};

int main() {
	Pair<string, int> student("Tom", 19);
	cout << student.key << " " << student.value;

	A1<int> a1;
	a1.Func("K");

	//参数不同，为不同的两个类
	//CArray<double, 40> a2;
	//CArray<int, 50> a3;

	//(2)类模板从模板类派生
	B3<char> obj3;

	//(3)类模板从普通类派生
	B4<char> obj4;

	B5 obj5;

	return 0;
}
