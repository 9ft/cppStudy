#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

template<class T>
class My_ostream_iterator: public iterator<output_iterator_tag, T> {
private:
	string sep; //分隔符
	ostream & os;
public:
	My_ostream_iterator(ostream & o, string s) :
			sep(s), os(o) {
	}
	void operator ++() {
	}
	; // ++只需要有定义即可, 不需要做什么
	My_ostream_iterator & operator *() {
		return *this;
	}
	My_ostream_iterator & operator =(const T & val) {
		os << val << sep;
		return *this;
	}
};
int main() {

	int a[5] = { 1, 2, 3, 2, 5 };
	int b[6] = { 1, 2, 3, 2, 5, 6 };
	ostream_iterator<int> oit(cout, ",");
	int * p = remove(a, a + 5, 2);
	cout << "1) ";
	copy(a, a + 5, oit);
	cout << endl; //输出 1) 1,3,5,2,5,
	cout << "2) " << p - a << endl; //输出 2) 3
	vector<int> v(b, b + 6);
	remove(v.begin(), v.end(), 2);
	cout << "3) ";
	copy(v.begin(), v.end(), oit);
	cout << endl;
	//输出 3) 1,3,5,6,5,6,
	cout << "4) ";
	cout << v.size() << endl;
	//v中的元素没有减少,输出 4) 6
	return 0;

}
