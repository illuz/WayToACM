/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva11137.cpp
*  Create Date: 2013-11-09 01:21:37
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>

const int MAXN = 10010;

long long dp[MAXN];
int a[30], n;

int main() {
	for (int i = 1; i <= 21; i++)
		a[i] = i * i * i;
	while (scanf("%d", &n) != EOF) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= 21; i++)
			for (int j = a[i]; j <= n; j++)
				dp[j] += dp[j - a[i]];
		printf("%lld\n", dp[n]);
	}
	return 0;
}

