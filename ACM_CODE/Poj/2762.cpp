/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2762.cpp
*  Create Date: 2014-08-15 14:49:47
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <stack>
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 20010;

stack<int> S;
vector<int> G[N], G2[N];
int dfn[N], low[N], sccno[N], id[N], tclock, scccnt;
int t, n, m, x, y, dfsdep;
bool vis[N];

void tarjan(int u) {
	dfn[u] = low[u] = ++tclock;
	S.push(u);

	int sz = G[u].size();
	repf (i, 0, sz - 1) {
		int v = G[u][i];
		if (!dfn[v]) {				// v not visited
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (!sccno[v]) {		// v not belong to scc, so it was in the stack
			low[u] = min(low[u], dfn[v]);
		}
	}

	if (low[u] == dfn[u]) {
		scccnt++;
		int v = -1;
		while (v != u) {
			v = S.top();
			S.pop();
			sccno[v] = scccnt;
		}
	}
}

void find_scc() {
	tclock = scccnt = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(sccno, 0, sizeof(sccno));

	repf (i, 1, n) {
		if (!dfn[i]) {
			tarjan(i);
		}
	}
}

void dfs(int u, int d) {
	vis[u] = 1;
	dfsdep = max(dfsdep, d);
	int sz = G2[u].size();
	repf (i, 0, sz - 1)
		if (!vis[G2[u][i]])
			dfs(G2[u][i], d + 1);
}

void read() {
	scanf("%d%d", &n, &m);

	repf (i, 0, n) {
		G[i].clear();
		G2[i].clear();
	}

	while (m--) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
	}
}

// shrink the point and calculate the indegree and outdegree
void solve() {
	
	memset(id, 0, sizeof(id));

	repf (u, 1, n) {
		int sz = G[u].size();
		repf (i, 0, sz - 1) {
			int v = G[u][i];
			if (sccno[u] != sccno[v]) {
				G2[sccno[u]].push_back(sccno[v]);
				id[sccno[v]]++;
			}
		}
	}

	memset(vis, 0, sizeof(vis));
	dfsdep = 1;
	repf (i, 1, scccnt) {
		if (id[i] == 0) {
			dfs(i, 1);
			break;
		}
	}
	//printf("%d\n", dfsdep);
	//printf("%d\n", scccnt);

	if (dfsdep == scccnt) {
		puts("Yes");
	} else {
		puts("No");
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		read();
		find_scc();
		solve();
	}
	return 0;
}

