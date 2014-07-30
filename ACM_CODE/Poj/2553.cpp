/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2553.cpp
*  Create Date: 2014-07-30 16:09:13
*  Descripton:  tarjan
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <stack>
#include <set>
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 5005;

vector<int> G[N];
stack<int> S;
int low[N], dfn[N], sccno[N], tclock, scccnt;
int id[N], od[N];
int n, m, r1, r2;

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
	repf (i, 1, n)
		G[i].clear();

	repf (i, 1, m) {
		scanf("%d%d", &r1, &r2);
		G[r1].push_back(r2);
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

	set<int> dscc;			// not outdegree scc id
	vector<int> ans;
	repf (i, 1, scccnt) {
		if (od[i] == 0) {
			dscc.insert(i);
		}
	}
	repf (i, 1, n) {
		if (dscc.count(sccno[i])) {
			ans.push_back(i);
		}
	}
	int sz = ans.size();
	if (!sz) {
		puts("");
		return;
	}
	repf (i, 0, sz - 2) {
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[sz - 1]);
}

int main() {
	while (~scanf("%d%d", &n, &m) && n) {
		read();
		find_scc();
		solve();
	}
	return 0;
}

