/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10271.cpp
*  Create Date: 2013-11-13 00:56:45
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define sqr(a) ((a) * (a))

int dp[5010][1010];
int a[5010], n, k, t;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &k, &n);
		k += 8;

		for (int i = n; i >= 1; i--)
			scanf("%d", &a[i]);
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				dp[i][j] = 0x7ffffff;

		for (int i = 3; i <= n; i++)
			for (int j = 1; j <= k; j++)
				if (i >= j * 3)
					dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + sqr(a[i - 1] - a[i]));

		printf("%d\n", dp[n][k]);
	}
	return 0;
}

