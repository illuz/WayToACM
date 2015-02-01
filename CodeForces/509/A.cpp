/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2015-01-31 20:15:02
*  Descripton:  simulate
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 0;

int n;

int main() {
	cin >> n;
	vector<int> num(n, 1);
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			num[j] += num[j - 1];
	cout << num[n - 1] << endl;
	return 0;
}

