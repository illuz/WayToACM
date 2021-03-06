/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        Tarjan.cpp
*  Create Date: 2014-08-07 10:26:39
*  Descripton:  tarjan, directed, strong connected componenet
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 20010;

stack<int> S;
vector<int> G[N];
int dfn[N], low[N], sccno[N], tclock, scccnt;
int id[N], od[N];
int t, n, m, x, y;

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

	repf (i, 0, n - 1) {
		if (!dfn[i]) {
			tarjan(i);
		}
	}
}

void read() {
	scanf("%d%d", &n, &m);

	repf (i, 0, n)
		G[i].clear();

	while (m--) {
		scanf("%d%d", &x, &y);
		x--;
		y--;
		G[x].push_back(y);
	}
}

// shrink the point and calculate the indegree and outdegree
int solve() {
	if (scccnt == 1)
		return 0;
	memset(id, 0, sizeof(id));
	memset(od, 0, sizeof(od));

	repf (u, 0, n - 1) {
		int sz = G[u].size();
		repf (i, 0, sz - 1) {
			int v = G[u][i];
			if (sccno[u] != sccno[v]) {
				id[sccno[v]]++;
				od[sccno[u]]++;
			}
		}
	}

	int idnum = 0, odnum = 0;
	repf (i, 1, scccnt) {
		idnum += (id[i] == 0);
		odnum += (od[i] == 0);
	}

	return max(idnum, odnum);
}

int main() {

	return 0;
}

