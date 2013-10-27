/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva437.cpp
*  Create Date: 2013-10-19 20:39:58
*  Descripton:  dp, dag, memory
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 230;

int n, ans, cas = 1;
bool g[MAXN][MAXN];
int dp[MAXN];

struct P{
	int x, y, z;
} p[MAXN];

bool check(int i, int j) {
	if (p[i].x < p[j].x && p[i].y < p[j].y)
		return true;
	if (p[i].x < p[j].y && p[i].y < p[j].x)
		return true;
	return false;
}

int dfs(int u) {
	if (dp[u] != -1) return dp[u];
	dp[u] = p[u].z;
	for (int i = 0; i < n; i++) if (g[u][i])
		dp[u] = max(dp[u], dfs(i) + p[u].z);
	return dp[u];
}

int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
			p[n + i].x = p[i].x; p[n + i].y = p[i].z; p[n + i].z = p[i].y;
			p[2 * n + i].x = p[i].y; p[2 * n + i].y = p[i].z; p[2 * n + i].z = p[i].x;
		}
		n *= 3;
		memset(g, 0, sizeof(g));
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++)
			for (int j = 0; j <n; j++) {
				g[i][j] = check(i, j);
				g[j][i] = check(j, i);
			}
		ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, dfs(i));
		printf("Case %d: maximum height = %d\n", cas++, ans);
	}
	return 0;
}
