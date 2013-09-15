/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        B.cpp
*  Create Date: 2013-09-14 23:50:09
*  Descripton:  greedy 
*/

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int a, b, c, sum, M, r[3];
	cin >> a >> b >> c;
	sum = a + b + c;
	M = max(a, max(b, c));
	if (sum - M >= M && ((sum - M) - M) % 2 == 0) {
		int ta = ((sum - M) - M) / 2;
		if (a >= b && a >= c) {
			r[1] = ta;
			r[0] = b - ta;
			r[2] = c - ta;
		}
		else if (b >= a && b >= c) {
			r[2] = ta;
			r[0] = a - ta;
			r[1] = c - ta;
		}
		else {
			r[0] = ta;
			r[1] = b - ta;
			r[2] = a - ta;
		}
		printf("%d %d %d\n", r[0], r[1], r[2]);
	}
	else printf("Impossible\n");
	return 0;
} 
