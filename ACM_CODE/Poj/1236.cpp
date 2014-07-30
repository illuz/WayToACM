/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1236.cpp
*  Create Date: 2014-07-30 15:13:12
*  Descripton:  Tarjan 
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

const int N = 105;

vector<int> G[N];
stack<int> S;
int low[N], dfn[N], sccno[N], tclock, scccnt;
int id[N], od[N];
int n, rd;

void tarjan(int u) {
	low[u] = dfn[u] = ++tclock;
	S.push(u);

	int sz = G[u].size();
	repf (i, 0, sz - 1) {
		int v = G[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (!sccno[v]) {
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

void read() {
	repf (i, 1, n) {
		G[i].clear();
		while (scanf("%d", &rd) && rd) {
			G[i].push_back(rd);
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

void solve() {
	if (scccnt == 1) {
		printf("1\n0\n");
		return;
	}

	memset(id, 0, sizeof(id));
	memset(od, 0, sizeof(od));

	repf (u, 1, n) {
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

	printf("%d\n%d\n", idnum, max(idnum, odnum));
}

int main() {
	while (~scanf("%d", &n)) {
		read();
		find_scc();
		solve();
	}
	return 0;
}

