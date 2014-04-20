//============================================================================
// Name        : W8-01_STLIntro.cpp
// Author      : Mindy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

int main() {
	vector<int> v; //一个存放int元素的数组，一开始里面没有元素
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::const_iterator i; //常量迭代器
	for (i = v.begin(); i != v.end(); ++i)
		cout << *i << ",";
	cout << endl;

	vector<int>::reverse_iterator r; //反向迭代器
	for (r = v.rbegin(); r != v.rend(); r++)
		cout << *r << ",";
	cout << endl;

	vector<int>::iterator j; //非常量迭代器
	for (j = v.begin(); j != v.end(); j++)
		*j = 100;
	for (i = v.begin(); i != v.end(); i++)
		cout << *i << ",";

	//find算法示例
	vector<int>::iterator p;

	p = find(v.begin(), v.end(), 3);
	if (p != v.end())
		cout << *p << endl;

	p = find(v.begin(), v.end(), 9);
	if (p == v.end())
		cout << "not found " << endl;

	p = find(v.begin() + 1, v.end() - 2, 1); //整个容器：[1,2,3,4]， 查找区间：[2,3)
	if (p != v.end())
		cout << *p << endl;

	int array[10] = {10,20,30,40};
	int * pp = find(array, array + 4, 20); //数组名是迭代器
	cout << *pp << endl;

	return 0;
}
