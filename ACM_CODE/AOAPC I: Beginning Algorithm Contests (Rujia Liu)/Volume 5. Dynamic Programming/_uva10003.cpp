/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        _uva10003.cpp
*  Create Date: 2013-09-20 16:04:57
*  Descripton:  dp 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 55;
int s[MAXN], d[MAXN][MAXN], len, n;

int dp(int b, int e) {
	if (d[b][e] >= 0) return d[b][e];
	d[b][e] = dp(b, b + 1) + dp(b + 1, e) + s[e] - s[b];
	for (int i = b + 2; i < e; i++) {
		int tt = dp(b, i) + dp(i, e) + s[e] - s[b];
		d[b][e] = min(d[b][e], tt);
	}
	return d[b][e];
}

int main() {
	while (scanf("%d", &len) && len) {
		scanf("%d", &n);
		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= n + 1; j++)
				if (j - i == 1)
					d[i][j] = 0;
				else
					d[i][j] = -1;
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i + 1]);
		s[n + 1] = len;
		printf("The minimum cutting is %d.\n", dp(0, n + 1));
	}
	return 0;
}

