/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva138.cpp
*  Create Date: 2013-11-18 13:02:07
*  Descripton:  math, pell equation
*/

#include <cstdio>

int main() {
	int t, n;
	int xi = 3, yi = 1;
	for (int i = 0; i < 10; i++) {
		t = 3 * xi + 8 * yi;
		n = 3 * yi + xi;
		printf("%10d%10d\n", n, (t - 1) >> 1);
		xi = t;
		yi = n;
	}
	return 0;
}

