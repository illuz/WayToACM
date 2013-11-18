/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10051.cpp
*  Create Date: 2013-11-07 15:39:55
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>

const int MAXN = 3010;

char up[6][10] = {"front", "back", "left", "right", "top", "bottom"};
int dp[MAXN], path[MAXN], color[6];
int m, n;

struct Cube {
	int top, bot;
	int wei, pos;
	Cube() { };
	Cube(int t, int b, int w, int p) {
		top = t; bot = b; wei = w; pos = p;
	}
} c[MAXN]; 

void print(int p) {
	if (p == -1) return;
	print(path[p]);
	printf("%d %s\n", c[p].wei, up[c[p].pos]);
}

int main() {
	int cas = 0;
	while (scanf("%d", &n) && n) {
		m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 6; j++)
				scanf("%d", &color[j]);
			for (int j = 0; j < 6; j++)
				if (j % 2)
					c[m++] = Cube(color[j], color[j - 1], i + 1, j);
				else
					c[m++] = Cube(color[j], color[j + 1], i + 1, j);
		}

		memset(dp, 0, sizeof(dp));
		memset(path, -1, sizeof(path));
		for (int i = 0; i < m; i++)
			for (int j = i + 1; j < m; j++)
				if (c[i].wei < c[j].wei && c[i].bot == c[j].top && dp[j] < dp[i] + 1) {
					dp[j] = dp[i] + 1;
					path[j] = i;
				}

		int ans = 0, p = 0;
		for (int i = 1; i < m; i++)
			if (ans < dp[i])
				ans = dp[i], p = i;

		if (cas)
			printf("\n");
		printf("Case #%d\n%d\n", ++cas, ans + 1);
		print(p);
	}
	return 0;
}

