/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        sjtu1319.cpp
*  Create Date: 2014-11-02 00:20:19
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 60;

char g[N][N];
int n, m, t;
ll ans[3];

void deal(int x, int y) {
	bool found = false;
	int tmp = 1;
	while (g[x][y] != 0) {
		if (found) {
			if (g[x][y] == '.') tmp++;
			else {
				if (g[x][y] == 'R') ans[0] += min(t, tmp);
				else if (g[x][y] == 'G') ans[1] += min(t, tmp);
				else if (g[x][y] == 'B') ans[2] += min(t, tmp);
				tmp = 1;
			}
		} else if (g[x][y] != '.') {
			if (g[x][y] == 'R') ans[0] += t;
			else if (g[x][y] == 'G') ans[1] += t;
			else if (g[x][y] == 'B') ans[2] += t;
			found = true;
		}
		x++;
		y++;
	}
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(g, 0, sizeof(g));
		ans[0] = ans[1] = ans[2] = 0;
		repf (i, 0, n - 1)
			scanf("%s", g[i]);
		scanf("%d", &t);
		for (int i = 0; g[i][0]; i++)
			deal(i, 0);
		for (int i = 1; g[0][i]; i++)
			deal(0, i);
		printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
	}
	return 0;
}

