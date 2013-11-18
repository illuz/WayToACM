/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        njupt1581.cpp
*  Create Date: 2013-11-13 00:23:21
*  Descripton:  dp 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define sqr(a) ((a) * (a))

int dp[110][55];
int n, k, a[110];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	if (n < (k + 3) * 2) {
		puts("-1");
		return 0;
	}

	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k + 3; j++)
			dp[i][j] = 0x7ffffff;
	dp[0][0] = 0;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= k + 3; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + sqr(a[i] - a[i - 1]));
		}

	printf("%d\n", dp[n][k + 3]);
	return 0;
}

