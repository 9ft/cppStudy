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

//��ģ������Ͳ����ͺ���ģ������Ͳ����ǲ���һ�µ�
template<class T>
class A {
public:
	template<class T2> //��Ա����ģ��
	void Func(T2 t) {
		cout << t;
	}
};

//��ģ��������Ͳ���
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

//(1)��ģ�����ģ������
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

//(2)��ģ���ģ��������
template<class T1, class T2>
class A11 {
	T1 v1;
	T2 v2;
};
template<class T>
class B11: public A11<int, double> {
	T v;
};

//(3)��ģ�����ͨ������

int main() {
	Pair<string, int> student("Tom", 19);
	cout << student.key << " " << student.value;

	A<int> a;
	a.Func("K");

	//������ͬ��Ϊ��ͬ��������
	//CArray<double, 40> a2;
	//CArray<int, 50> a3;

	B11<char> obj1;

	return 0;
}
