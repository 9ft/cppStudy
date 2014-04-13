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
class A1 {
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

//(2)��ģ���ģ��������
template<class T1, class T2>
class A3 {
	T1 v1;
	T2 v2;
};
template<class T>
class B3: public A3<int, double> {
	T v;
};

//(3)��ģ�����ͨ������
class A4 {
	int v1;
};
template<class T>
class B4: public A4 {
	T v;
};

//(4)��ͨ���ģ��������
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

	//������ͬ��Ϊ��ͬ��������
	//CArray<double, 40> a2;
	//CArray<int, 50> a3;

	//(2)��ģ���ģ��������
	B3<char> obj3;

	//(3)��ģ�����ͨ������
	B4<char> obj4;

	B5 obj5;

	return 0;
}
