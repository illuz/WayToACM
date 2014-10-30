/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-10-06 22:48:08
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 30;

int n, m;
char c[N], r[N];
int cnt, vis[N][N];

void dfs(int x, int y) {
	if (!c[x] || !r[y] || vis[x][y])
		return;
	vis[x][y] = 1;
	cnt++;
	if (c[x] == '>') dfs(x, y + 1);
	else dfs(x, y - 1);
	if (r[y] == 'v') dfs(x + 1, y);
	else dfs(x - 1, y);
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s%s", c + 1, r + 1);
	repf (i, 1, n) repf (j, 1, m) {
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		dfs(i, j);
		if (cnt != m * n) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
		
	return 0;
}

