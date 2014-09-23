/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3.cpp
*  Create Date: 2014-09-20 12:22:21
*  Descripton:  
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 110;
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int t, d[N][N][8];
char g[N][N];
int n;

int dfs(int x, int y, int t) {
	if (d[x][y][t] != -1)
		return d[x][y][t];
	if (g[x + dx[t]][y + dy[t]] == '.')
		return d[x][y][t] = 1 + dfs(x + dx[t], y + dy[t], t);
	else
		return d[x][y][t] = 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	while (~scanf("%d", &n) && n) {
		memset(g, 0, sizeof(g));
		memset(d, -1, sizeof(d));
		int ans = 0;
		repf (i, 1, n)
			scanf("%s", g[i] + 1);
		repf (i, 1, n) repf (j, 1, n) {
			if (g[i][j] == '.') {
				ans = max(ans, dfs(i, j, 0) + dfs(i, j, 2) - 1);
				ans = max(ans, dfs(i, j, 1) + dfs(i, j, 2) - 1);
				ans = max(ans, dfs(i, j, 1) + dfs(i, j, 3) - 1);
				ans = max(ans, dfs(i, j, 0) + dfs(i, j, 3) - 1);
				ans = max(ans, dfs(i, j, 4) + dfs(i, j, 5) - 1);
				ans = max(ans, dfs(i, j, 4) + dfs(i, j, 6) - 1);
				ans = max(ans, dfs(i, j, 7) + dfs(i, j, 5) - 1);
				ans = max(ans, dfs(i, j, 7) + dfs(i, j, 6) - 1);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

