/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10306.cpp
*  Create Date: 2013-11-08 14:45:19
*  Descripton:  dp, bag 
*/

#include <cstdio>
#include <cstring>

#define min(x, y) (x) > (y) ? (y) : (x)

const int MAXN = 505;

int x[50], y[50], t, n, s;
int dp[MAXN][MAXN];
bool used[MAXN][MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		// the memset init numbers by bit
		memset(dp, 2, sizeof(dp));
		memset(used, 0, sizeof(used));

		scanf("%d%d", &n, &s);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &x[i], &y[i]);

		used[0][0] = 1;
		dp[0][0] = 0;
		int ans = 0x7ffffff;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= s - x[i]; j++)
				for (int k = 0; k <= s - y[i]; k++) {
					int tx = j + x[i], ty = k + y[i];
					if (used[j][k] && dp[tx][ty] > dp[j][k] + 1) {
						used[tx][ty] = true;
						dp[tx][ty] = dp[j][k] + 1;
						if (tx * tx + ty * ty == s * s)
							ans = min(ans, dp[tx][ty]);
					}
				}
		if (ans != 0x7ffffff)
			printf("%d\n", ans);
		else
			puts("not possible");
	}
	return 0;
}

