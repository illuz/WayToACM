/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10465.cpp
*  Create Date: 2013-10-19 19:31:00
*  Descripton:  dp, pack 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

int dp[MAXN];
int n, m, t;

int main() {
	while (scanf("%d%d%d", &n, &m, &t) != EOF) {
		int ans = 0;
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < t; i++)
			if (dp[i] != -1)
				dp[i + n] = max(dp[i] + 1, dp[i + n]);
		for (int i = 0; i < t; i++)
			if (dp[i] != -1)
				dp[i + m] = max(dp[i] + 1, dp[i + m]);
		for (int i = t; i >= 0; i--)
			if (dp[i] != -1) {
				ans = i;
				break;
			}
		printf("%d", dp[ans]);
		if (ans != t) printf(" %d", t - ans);
		puts("");
	}
	return 0;
}

