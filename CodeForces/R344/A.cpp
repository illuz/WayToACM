/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        A.cpp
*  Create Date: 2013-09-14 23:29:09
*  Descripton:  simulate 
*/

#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
	int n, t, tt, sum = 1;
	cin >> n;
	cin >> t;
	rep(i, n - 1) {
		cin >> tt;
		if (tt == t)
			continue;
		else {
			t = tt;
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
