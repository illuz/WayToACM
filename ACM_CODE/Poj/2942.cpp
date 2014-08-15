/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2942.cpp
*  Create Date: 2014-08-15 16:30:10
*  Descripton:  tarjan, bipartite
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

const int N = 1010;

struct Edge {
	int u;
	int v;
};

// cut points' bccno is no sense
int dfn[N], iscut[N], bccno[N], tclock, bcccnt;
int odd[N], color[N], A[N][N];
int cas = 0, n, m, u, v;
vector<int> G[N], bcc[N];

stack<Edge> S;

int tarjan(int u, int fa) {		// current node and father node
	int lowu = dfn[u] = ++tclock;
	int child = 0;		// number of child nodes

	int sz = G[u].size();
	repf (i, 0, sz - 1) {
		int v = G[u][i];
		Edge e = (Edge){u, v};
		if (!dfn[v]) {
			S.push(e);
			child++;
			int lowv = tarjan(v, u);
			lowu = min(lowu, lowv);

			if (lowv >= dfn[u]) {
				iscut[u] == true;
				bcc[++bcccnt].clear();		// push the nodes to bcc
				while (1) {
					Edge x = S.top();
					S.pop();
					if (bccno[x.u] != bcccnt) {
						bcc[bcccnt].push_back(x.u);
						bccno[x.u] = bcccnt;
					}
					if (bccno[x.v] != bcccnt) {
						bcc[bcccnt].push_back(x.v);
						bccno[x.v] = bcccnt;
					}
					if (x.u == u && x.v == v)
						break;
				}
			}	
		} else if (dfn[v] < dfn[u] && v != fa) {		// undirected so v != fa
			S.push(e);
			lowu = min(lowu, dfn[v]);
		}

	}
	if (fa < 0 && child == 1)	// if u is root
		iscut[u] = 0;
	return lowu;
}

void find_bcc(int n) {
	memset(dfn, 0, sizeof(dfn));
	memset(iscut, 0, sizeof(iscut));
	memset(bccno, 0, sizeof(bccno));
	tclock = bcccnt = 0;
	repf (i, 0, n - 1)
		if (!dfn[i])
			tarjan(i, -1);
}

bool bipartite(int u, int b) {
	int sz = G[u].size();
	repf (i, 0, sz - 1) {
		int v = G[u][i];
		if (bccno[v] != b)
			continue;
		if (color[v] == color[u])
			return false;
		if (!color[v]) {
			color[v] = 3 - color[u];
			if (!bipartite(v, b))
				return false;
		}
	}
	return true;
}

void read() {
	repf (i, 0, n - 1)
		G[i].clear();
	memset(A, 0, sizeof(A));
	repf (i, 0, m - 1) {
		scanf("%d%d", &u, &v);
		u--;
		v--;
		A[u][v] = A[v][u] = 1;
	}
	repf (u, 0, n - 1)
		repf (v, u + 1, n - 1) {
			if (!A[u][v]) {
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
}

void solve() {
	find_bcc(n);

	memset(odd, 0, sizeof(odd));
	repf (i, 1, bcccnt) {
		memset(color, 0, sizeof(color));
		int sz = bcc[i].size();
		repf (j, 0, sz - 1) {
			bccno[bcc[i][j]] = i;
		}

		int u = bcc[i][0];
		color[u] = 1;
		if (!bipartite(u, i))
			repf (j, 0, sz - 1) {
				odd[bcc[i][j]] = 1;
			}
	}
	int ans = n;
	repf (i, 0, n - 1)
		if (odd[i])
			ans--;
	printf("%d\n", ans);
}

int main() {
	while (~scanf("%d%d", &n, &m) && n) {
		read();
		solve();
	}
	return 0;
}

