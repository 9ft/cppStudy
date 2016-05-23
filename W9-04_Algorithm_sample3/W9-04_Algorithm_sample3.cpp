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
	int a[4] = { 1, 2, 3, 4 };
	My_ostream_iterator<int> oit(cout, "*");
	copy(a, a + 4, oit); //输出 1*2*3*4*
	ofstream oFile("test.txt", ios::out);
	My_ostream_iterator<int> oitf(oFile, "*");
	copy(a, a + 4, oitf); //向test.txt文件中写入 1*2*3*4*
	oFile.close();
	return 0;
}
