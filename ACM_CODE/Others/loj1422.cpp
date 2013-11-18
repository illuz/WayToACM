/*
 *  Author:      illuz <iilluzen[at]gmail.com>
 *  Blog:        http://blog.csdn.net/hcbbt
 *  File:        loj1422.cpp
 *  Create Date: 2013-11-11 13:53:33
 *  Descripton:  invertel dp 
 */

#include <cstdio>
#include <cstring>

#define min(a, b) ((a) < (b) ? (a) : (b))

const int MAXN = 110;
int dp[MAXN][MAXN], a[MAXN];
int n, t, cas;

int main() {
	scanf("%d", &t);
	for (cas = 0; cas < t; cas++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		for (int i = 0; i <= n; i++)
			for (int j = i; j <= n; j++)
				dp[i][j] = j - i + 1;

		for (int i = n - 1; i >= 1; i--)
			for (int j = i; j <= n; j++) {
				dp[i][j] = dp[i + 1][j] + 1;
				for (int k = i + 1; k <= j; k++)
					if (a[k] == a[i])
						dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
			}

		printf("Case %d: %d\n", cas + 1, dp[1][n]);
	}
	return 0;
}

