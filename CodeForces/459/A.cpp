/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-08-15 23:35:17
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 0;


int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int a;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		if (x1 == x2) {
			a = y1 - y2;
			cout << x1 + a << ' ' << y1 << ' ' << x2 + a << ' ' << y2 << endl;
		} else if (y1 == y2) {
			a = x1 - x2;
			cout << x1 << ' ' << y1 + a << ' ' << x2 << ' ' << y2 + a << endl;
		} else {
			if (abs(x1 - x2) != abs(y1 - y2)) {
				cout << -1 << endl;
				continue;
			}
			cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << endl;
		}
	}
	return 0;
}

