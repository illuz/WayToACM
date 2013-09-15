/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        C.cpp
*  Create Date: 2013-09-15 10:26:31
*  Descripton:  simulate 
*/

#include <iostream>
using namespace std;

int main() {
	long long a, b, t, cnt = 0;
	cin >> a >> b;
	while (b) {
		cnt += a / b;
		t = a % b;
		a = b;
		b = t;
	}
	cout << cnt << endl;
	return 0;
}

