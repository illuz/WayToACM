/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3352.cpp
*  Create Date: 2014-08-13 15:28:44
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 5010;

vector<int> G[N];
bool app[N][N], instack[N];
int n, r, u, v;
int dfn[N], low[N], dg[N], tclock;

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++tclock;
	instack[u] = 1;

	int sz = G[u].size();
	repf (i, 0, sz - 1) {
		int v = G[u][i];
		if (v == fa)
			continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		} else if (instack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void init(int n, int r) {
	memset(app, 0, sizeof(app));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(instack, 0, sizeof(instack));
	memset(dg, 0, sizeof(dg));
	repf (i, 1, n) {
		G[i].clear();
	}

	repf (i, 0, r - 1) {
		scanf("%d%d", &u, &v);
		if (!app[u][v]) {
			G[u].push_back(v);
			G[v].push_back(u);
			app[u][v] = app[v][u] = 1;
		}
	}
}

void solve() {
	tarjan(1, -1);
	repf (u, 1, n) {
		int sz = G[u].size();
		repf (i, 0, sz - 1) {
			int v = G[u][i];
			if (low[u] != low[v])
				dg[low[u]]++;
		}
	}

	int cnt = 0;
	repf (i, 1, n) {
		if (dg[i] == 1) {
			cnt++;
		}
	}

	printf("%d\n", (cnt + 1) / 2);
}

int main() {
	while (~scanf("%d%d", &n, &r)) {
		init(n, r);
		solve();
	}
	return 0;
}

