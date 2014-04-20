#include <iostream>
#include <list>
using namespace std;

class A { //������A, ������Ԫ����<, ==��<<
private:
	int n;
public:
	A(int n_) {
		n = n_;
	}
	friend bool operator<(const A &a1, const A& a2) {
		return a1.n < a2.n;
	}
	friend bool operator==(const A &a1, const A& a2) {
		return a1.n == a2.n;
	}
	friend ostream & operator<<(ostream &o, const A& a) {
		o << a.n;
		return o;
	}
};

//���庯��ģ��PrintList����ӡ�б��еĶ���
template<class T>
void PrintList(const list<T> & lst) {
	int tmp = lst.size();
	if (tmp > 0) {
		typename list<T>::const_iterator i;
		i = lst.begin();
		for (i = lst.begin(); i != lst.end(); i++)
			cout << *i << ",";
	}
}

int main() {
	list<A> lst1, lst2;

	lst1.push_back(1);
	lst1.push_back(3);
	lst1.push_back(2);
	lst1.push_back(4);
	lst1.push_back(2);

	lst2.push_back(10);
	lst2.push_front(20);
	lst2.push_back(30);
	lst2.push_back(30);
	lst2.push_back(30);
	lst2.push_front(40);
	lst2.push_back(40);

	cout << "1)";
	PrintList(lst1);
	cout << endl;

	cout << "2)";
	PrintList(lst2);
	cout << endl;

	lst2.sort(); //list������sort����
	cout << "3)";
	PrintList(lst2);
	cout << endl;

	lst2.pop_front();
	cout << "4)";
	PrintList(lst2);
	cout << endl;

	lst1.remove(2); //ɾ�����к�A(2)��ȵ�Ԫ��
	cout << "5)";
	PrintList(lst1);
	cout << endl;

	lst2.unique(); //ɾ�����к�ǰһ��Ԫ����ȵ�Ԫ��
	cout << "6)";
	PrintList(lst2);
	cout << endl;

	lst1.merge(lst2); //�ϲ�lst2��lst1�����lst2
	cout << "7)";
	PrintList(lst1);
	cout << endl;
	cout << "8)";
	PrintList(lst2);
	cout << endl;

	lst1.reverse();
	cout << "9)";
	PrintList(lst1);
	cout << endl;

	return 0;
}