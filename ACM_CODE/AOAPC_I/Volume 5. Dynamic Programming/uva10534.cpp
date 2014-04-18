/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10534.cpp
*  Create Date: 2013-11-07 14:54:49
*  Descripton:  LIS, nlogn
*/

#include <cstdio>
#include <cstring>
#include <climits>

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define max(a, b) ((a) < (b)) ? (a) : (b)

const int MAXN = 10010;

int a[MAXN], b[MAXN];
int nu[MAXN];
int n, t;

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%d", &nu[i]);
		t = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] > stk[top])
		}
	}
	return 0;
}

