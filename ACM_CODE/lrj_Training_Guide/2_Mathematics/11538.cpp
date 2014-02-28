/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11538.cpp
*  Create Date: 2014-02-28 08:55:06
*  Descripton:   
*/

#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

ull n, m;

int main() {
	while (cin >> n >> m && (n || m)) {
		if (n > m) swap(n, m);
		cout << n * m * (m + n - 2) + 2 * n * (n - 1) * (3 * m - n - 1) / 3 << endl;
	}
	return 0;
}

