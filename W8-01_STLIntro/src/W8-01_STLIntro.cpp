//============================================================================
// Name        : W8-01_STLIntro.cpp
// Author      : Mindy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> v; //һ�����intԪ�ص����飬һ��ʼ����û��Ԫ��
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::const_iterator i; //����������
	for (i = v.begin(); i != v.end(); ++i)
		cout << *i << ",";
	cout << endl;

	return 0;
}
