/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        a.cpp
*  Create Date: 2013-09-20 23:32:37
*  Descripton:  a 
*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int MAXN = 1001;
int n, ra, ri, a[MAXN];
int Max = -1000, Min = 1001;

int main() {
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &a[i]);
		if (Max < a[i]) {
			Max = a[i];
			ra = i;
		}
		if (Min > a[i]) {
			Min = a[i];
			ri = i;
		}
	}
	a[ra] = 1001;
	a[ri] = 1001;
	sort(a, a + n);
	if (n == 2)
		printf("%d %d\n", Max, Min);
	else {
		printf("%d", Max);
		rep(i, n - 2)
			printf(" %d", a[i]);
		printf(" %d\n", Min);
	}
	return 0;
}


