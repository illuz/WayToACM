/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10130.cpp
*  Create Date: 2013-10-19 16:12:18
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int dp[MAXN * 30];
int p[MAXN], w[MAXN];
int t, n, g, c, ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &p[i], &w[i]);
		scanf("%d", &g);
		while (g--) {
			scanf("%d", &c);
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++)
				for (int j = c; j >= 0; j--)
					if (j >= w[i])
						dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
			ans += dp[c];
		}
		printf("%d\n", ans);
	}
	return 0;
}

