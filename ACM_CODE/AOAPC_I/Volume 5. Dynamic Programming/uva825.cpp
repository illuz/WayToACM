/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva825.cpp
*  Create Date: 2013-10-25 14:04:00
*  Descripton:  dp, ricursion 
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

const int MAXN = 101;

int	g[MAXN][MAXN];
int dp[MAXN][MAXN];
int n, m, t;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d\n", &n, &m);
		memset(g, 0, sizeof(g));
		memset(dp, 0, sizeof(dp));
		g[1][1] = dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			int num;
			char ch[MAXN];
			scanf("%d", &num);
			gets(ch);
			for (int j = 0, tt = 0, len = strlen(ch); j <= len; j++)
				if (isdigit(ch[j]))
					tt = tt * 10 + ch[j] - '0';
				else
					g[num][tt] = true, tt = 0;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (!g[i][j])
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		printf("%d\n", dp[n][m]);
		if (t) printf("\n");
	}
	return 0;
}

