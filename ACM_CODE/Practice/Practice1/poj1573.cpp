/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        b.cpp
*  Create Date: 2013-10-09 23:09:29
*  Descripton:  poj1573, dfs, simutation
*/

#include <cstdio>
#include <cstring>

const int MAXN = 11;
char g[MAXN][MAXN];
int v[MAXN][MAXN];
int r, c, n;

void dfs(int x, int y, int s) {
	if (x < 0 || x >= r || y < 0 || y >= c) {
		printf("%d step(s) to exit\n", s - 1);
		return;
	}
	if (v[x][y]) {
		printf("%d step(s) before a loop of %d step(s)\n", v[x][y] - 1, s - v[x][y]);
		return;
	}
	v[x][y] = s;
	if (g[x][y] == 'N')
		dfs(x - 1, y, s + 1);
	else if (g[x][y] == 'S')
		dfs(x + 1, y, s + 1);
	else if (g[x][y] == 'W')
		dfs(x, y - 1, s + 1);
	else
		dfs(x, y + 1, s + 1);
}

int main() {
	while (scanf("%d%d%d\n", &r, &c, &n) && (r || c || n)) {
		for (int i = 0; i < r; i++)
			gets(g[i]);
		memset(v, 0, sizeof(v));
		dfs(0, n - 1, 1);
	}
	return 0;
}

