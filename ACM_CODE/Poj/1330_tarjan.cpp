/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1330_tarjan.cpp
*  Create Date: 2014-10-09 10:21:57
*  Descripton:  LCA tarjan
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 1e4 + 10;

int fa[N], rk[N];
int ind[N];			// indegree to find out the root
int anc[N];			// ancestor
bool vis[N];
vector<vector<int> > tree(N), Que(N);

int t, n, ans;

int Find(int x) {
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

int Union(int x, int y) {
	int a = Find(x), b = Find(y);
	if (a == b) return 0;
	if (rk[a] <= rk[b])
		fa[a] = b, rk[b] += rk[a];
	else
		fa[b] = a, rk[a] += rk[b];
	return 1;
}

void LCA(int u) {
	anc[u] = u;
	int sz = tree[u].size();
	repf (i, 0, sz - 1) {
		LCA(tree[u][i]);
		Union(u, tree[u][i]);
		anc[Find(u)] = u;
	}
	vis[u] = 1;
	sz = Que[u].size();
	repf (i, 0, sz - 1) {
		if (vis[Que[u][i]]) {
			ans = anc[Find(Que[u][i])];
			return;		// just one query
		}
	}
}

void init() {
	int q, s, t;
	scanf("%d", &n);
	repf (i, 1, n) {
		rk[i] = 1;
		fa[i] = i;
		ind[i] = vis[i] = 0;
		tree[i].clear();
		Que[i].clear();
	}

	repf (i, 1, n - 1) {		// it given a tree
		scanf("%d%d", &s, &t);
		tree[s].push_back(t);
		ind[t]++;
	}

	q = 1;		// just one query
	repf (i, 0, q - 1) {
		scanf("%d%d", &s, &t);
		Que[s].push_back(t);
		Que[t].push_back(s);
	}
}

void solve() {
	ans = 0;
	repf (i, 1, n)	// find the root
		if (!ind[i]) {
			LCA(i);
			break;
		}
	printf("%d\n", ans);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		init();
		solve();
	}
	return 0;
}

