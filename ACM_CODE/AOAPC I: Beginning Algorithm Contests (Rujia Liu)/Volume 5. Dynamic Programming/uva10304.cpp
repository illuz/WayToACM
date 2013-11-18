/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10304.cpp
*  Create Date: 2013-11-12 22:32:08
*  Descripton:  invertel dp 
*/

#include <cstdio>
#include <cstring>

#define min(a, b) ((a) < (b) ? (a) : (b))

const int MAXN = 210;
int n, a[MAXN], sum[MAXN];
int dp[MAXN][MAXN];

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}

		for (int d = 2; d <= n; d++)
			for (int l = 1; l + d - 1 <= n; l++) {
				int r = l + d - 1;
				dp[l][r] = 0x7ffffff;
				for (int i = l; i <= r; i++)
					dp[l][r] = min(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + sum[r] - sum[l - 1] - a[i]);
			}

		printf("%d\n", dp[1][n]);
	}
	return 0;
}

