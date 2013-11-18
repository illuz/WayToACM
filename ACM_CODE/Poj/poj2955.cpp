/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        poj2955.cpp
*  Create Date: 2013-11-11 14:47:59
*  Descripton:  intervel dp 
*/

#include <cstdio>
#include <cstring>

#define check(i, j) ((str[i] == '[' && str[j] == ']') || (str[i] == '(' && str[j] == ')'))
#define max(a, b) ((a) > (b) ? (a) : (b))

const int MAXN = 110;
char str[MAXN];
int dp[MAXN][MAXN], n;

int solve(int i, int j) {
	if (dp[i][j]) return dp[i][j];
	if (j <= i) return 0;
	if (j == i + 1) {
		if (check(i, j))
			return dp[i][j] = 2;
		else
			return 0;
	}

	dp[i][j] = solve(i + 1, j);
	for (int k = i + 1; k <= j; k++)
		if (check(i, k)) 
			dp[i][j] = max(dp[i][j], solve(i + 1, k - 1) + solve(k + 1, j) + 2);
	return dp[i][j];
}

int main() {
	while (scanf("%s", str) && strcmp(str, "end")) {
		memset(dp, 0, sizeof(dp));
		printf("%d\n", solve(0, strlen(str) - 1));
	}
	return 0;
}

