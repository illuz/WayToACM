/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10617.cpp
*  Create Date: 2013-11-09 00:28:31
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>

#define max(a, b) (a) > (b) ? (a) : (b)

const int MAXN = 65;

long long dp[MAXN][MAXN];
char str[MAXN];
int t;

long long solve(int beg, int end) {
	if (-1 != dp[beg][end])
		return dp[beg][end];
	if (beg >= end)
		return dp[beg][end] = (beg == end ? 1 : 0);
	else {
		if (str[beg] == str[end])
			dp[beg][end] = max(dp[beg][end], solve(beg + 1, end) + solve(beg, end - 1) + 1);
		else
			dp[beg][end] = max(dp[beg][end], solve(beg + 1, end) + solve(beg, end - 1) - solve(beg + 1, end - 1));
		return dp[beg][end];
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));

		scanf("%s", str);
		printf("%lld\n", solve(0, strlen(str) - 1));
	}
	return 0;
}
