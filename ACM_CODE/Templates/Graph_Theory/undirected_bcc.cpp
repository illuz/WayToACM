/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        undirected_bcc.cpp
*  Create Date: 2014-08-13 10:36:13
*  Descripton:  undirected_bcc
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 0;

struct Edge {
	int u;
	int v;
};

// cut points' bccno is no sense
int dfn[N], iscut[N], bccno[N], tclock, bcccnt;
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

int main() {

	return 0;
}

