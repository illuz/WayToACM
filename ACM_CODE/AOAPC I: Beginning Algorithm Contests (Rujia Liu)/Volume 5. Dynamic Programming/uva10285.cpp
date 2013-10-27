/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10285.cpp
*  Create Date: 2013-10-19 19:46:21
*  Descripton:  dp, memory 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int x[] = {-1, 1, 0, 0};
const int y[] = {0, 0, -1, 1};

int dp[MAXN][MAXN];
int g[MAXN][MAXN];
int n, m, t, ans;
char name[51];

int dfs(int i, int j) {
	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = 0;
	for (int k = 0; k < 4; k++) {
		int tx = i + x[k];
		int ty = j + y[k];
		if (g[tx][ty] < g[i][j])
			dp[i][j] = max(dp[i][j], dfs(tx, ty));
	}
	return ++dp[i][j];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s%d%d", name, &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &g[i][j]);
		for (int i = 0; i <= m + 1; i++)
			g[0][i] = g[n + 1][i] = MAXN;
		for (int i = 0; i <= n + 1; i++)
			g[i][0] = g[i][m + 1] = MAXN;
		memset(dp, -1, sizeof(dp));
		ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				ans = max(ans , dfs(i, j));
		printf("%s: %d\n", name, ans);
	}
	return 0;
}

