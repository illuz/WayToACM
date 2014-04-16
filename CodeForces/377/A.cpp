/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-04-16 16:41:27
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};

const int N = 510;

int n, m, k, cnt;
int vis[N][N];
char g[N][N];

void dfs(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '.' || vis[x][y])
		return;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);
	vis[x][y] = cnt++;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);	
	for (int i = 0; i < n; i++)
		scanf("%s", g[i]);

	cnt = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == '.') {
				dfs(i, j);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++)
						if (g[i][j] == '#') putchar(g[i][j]);
						else if (vis[i][j] > k) putchar('.');
						else putchar('X');
					puts("");
				}
				return 0;
			}
}

