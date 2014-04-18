/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        348.cpp
*  Create Date: 2013-09-26 20:01:23
*  Descripton:  dp, martrix 
*/

#include <cstdio>
#include <cstring>
const int MAXN = 15;
const int INF = 0x7fffffff;
int x[MAXN], y[MAXN];
int d[MAXN][MAXN], r[MAXN][MAXN];

int dp(int a, int b) {
	if (d[a][b] != -1) return d[a][b];
	r[a][b] = a;
	if (a == b) return d[a][b] = 0;
	d[a][b] = INF;
	int t;
	for (int i = a; i < b; i++) {
		t = dp(a, i) + dp(i + 1, b) + x[a] * y[i] * y[b];
		if (t < d[a][b]) {
			d[a][b] = t;
			r[a][b] = i;
		}
	}
	return d[a][b];
}

void print(int a, int b) {
	if (a > b) return;
	if (a == b) 
		printf("A%d", a + 1);
	else {
		printf("(");
		print(a, r[a][b]);
		printf(" x ");
		print(r[a][b] + 1, b);
		printf(")");
	}
}

int main() {
	int n, cas = 0;
	while (scanf("%d", &n) && n) {
		memset(d, -1, sizeof(d));
		for (int i = 0; i < n; i++)
			scanf("%d%d", &x[i], &y[i]);
		// dp
		dp(0, n - 1);
		printf("Case %d: ", ++cas);
		print(0, n - 1);
		puts("");
	}
	return 0;
}

