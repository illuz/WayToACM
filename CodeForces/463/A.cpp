/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        A.cpp
*  Create Date: 2014-08-30 15:41:45
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 110;

int x[N], y[N];
int n, s;

int main() {
	int mmax = -1;
	scanf("%d%d", &n, &s);
	repf (i, 1, n) {
		scanf("%d%d", &x[i], &y[i]);
		if (x[i] < s) {
			mmax = max(mmax, (100 - y[i]) % 100);
		}
		if (x[i] == s && y[i] == 0) {
			mmax = max(mmax, 0);
		}
	}
	printf("%d\n", mmax);

	return 0;
}

