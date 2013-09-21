/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva674.cpp
*  Create Date: 2013-09-20 13:48:56
*  Descripton:  dp, low to up
*/

#include <cstdio>
const int MAXN = 8000;
int n, coin[5] = {1, 5, 10, 25, 50};
long long dp[MAXN] = {1};

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < MAXN - 100; j++)
			dp[j + coin[i]] += dp[j];

	while (scanf("%d", &n) != EOF)
		printf("%lld\n", dp[n]);
	return 0;
}

