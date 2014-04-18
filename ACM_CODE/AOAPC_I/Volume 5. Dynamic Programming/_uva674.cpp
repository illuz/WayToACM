/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        _uva674.cpp
*  Create Date: 2013-09-20 14:00:42
*  Descripton:  dp, memorial 
*/

#include <cstdio>
#include <cstring>
const int MAXN = 8000;
const int coin[5] = {1, 5, 10, 25, 50};
int n;
long long dp[MAXN][5];

long long solve(int i, int s) {
	if (dp[s][i] != -1)
		return dp[s][i];
	dp[s][i] = 0;
	for (int j = i; j < 5 && s >= coin[j]; j++)
		dp[s][i] += solve(j, s - coin[j]);
	return dp[s][i];
}

int main() {
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 5; i++)
		dp[0][i] = 1;
	while (scanf("%d", &n) != EOF)
		printf("%lld\n", solve(0, n));
	return 0;
}

