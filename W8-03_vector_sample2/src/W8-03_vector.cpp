//============================================================================
// Name        : W8-03_vector.cpp
// Author      : Mindy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	//二维动态数组 vector<vector<int>> v(3);
	//v有3个元素,
	//每个元素都是vector<int> 容器

	vector<vector<int> > v(3);
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < 4; ++j)
			v[i].push_back(j);
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}
