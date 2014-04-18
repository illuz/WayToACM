/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva116.cpp
*  Create Date: 2013-09-20 20:56:07
*  Descripton:  dp, memorial 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 102;
int dis[MAXN][MAXN], map[MAXN][MAXN], n, m;

int cg(int x) {
	if (x == 0) x = n;
	else if (x == n + 1) x = 1;
	return x;
}

int dp(int x, int y) {
	x = cg(x);
	if (dis[x][y] != -0xffffff) return dis[x][y];
	return dis[x][y] = map[x][y] + min(min(dp(x - 1, y + 1), dp(x, y + 1)), dp(x + 1, y + 1));
}

void print(int x, int y) {
	if (y < m)
		printf("%d ", x);
	else {
		printf("%d\n", x);
		return;
	}
	int a[3] = {cg(x - 1), cg(x), cg(x + 1)};
	sort(a, a + 3);
	int tt = dis[x][y] - map[x][y];
	if (tt == dis[a[0]][y + 1])
		print(a[0], y + 1);
	else if (tt == dis[a[1]][y + 1])
		print(a[1], y + 1);
	else
		print(a[2], y + 1);
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				scanf("%d", &map[i][j]);
				if (j == m) dis[i][j] = map[i][j];
				else dis[i][j] = -0xffffff;
			}
		int Min = 0xffffff, t, rx, ry;
		for (int i = 1; i <= n; i++) {
			t = dp(i, 1);
			if (t < Min)
				rx = i, Min = t;
		}
		print(rx, 1);
		printf("%d\n", Min);
	}
	return 0;
}

