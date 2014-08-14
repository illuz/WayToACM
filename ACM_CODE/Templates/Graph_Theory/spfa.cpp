/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3013_spfa.cpp
*  Create Date: 2014-07-27 15:44:45
*  Descripton:  spfa 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <queue>
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 50100;
const long long INF = (long long)(1<<16)*N;

struct Edge {
	int from, to;
	int spst;
};

struct SPFA {
	int n, m;
	vector<Edge> edges;
	vector<int> G[N];	// the edges which from i
	bool vis[N];
	long long d[N];	// sps
	int p[N];		// prevent

	void init(int _n) {
		n = _n;
	}

	void relief() {
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int spst) {
		// if non-sprected, add twice
		edges.push_back((Edge){from, to, spst});
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void spfa(int s) {
		queue<int> Q;
		while (!Q.empty())
			Q.pop();
		for (int i = 0; i < n; i++) {
			d[i] = INF;
			vis[i] = 0;
		}
		d[s] = 0;
		vis[s] = 1;
		Q.push(s);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			vis[u] = 0;
			for (int i = 0; i < G[u].size(); i++) {
				Edge& e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.spst) {
					d[e.to] = d[u] + e.spst;
					p[e.to] = G[u][i];
					if (!vis[e.to]) {
						vis[e.to] = 1;
						Q.push(e.to);
					}
				}
			}
		}
		
	}
};

int t;
int e, v, x, y, d, w[N];

int main() {
	scanf("%d", &t);
	SPFA sp;

	while (t--) {
		scanf("%d%d", &v, &e);
		sp.init(v);

		repf (i, 0, v - 1) {
			scanf("%d" ,&w[i]);
		}
		repf (i, 0, e - 1) {
			scanf("%d%d%d", &x, &y, &d);
			sp.AddEdge(x - 1, y - 1, d);
			sp.AddEdge(y - 1, x - 1, d);
		}
		sp.spfa(0);

		long long ans = 0;
		bool ring = false;
		repf (i, 0, v - 1) {
			if (sp.d[i] == INF) {
				ring = true;
			}
			ans += w[i] * sp.d[i];
		}
		if (ring) {
			cout << "No Answer" << endl;
		} else {
			cout << ans << endl;
		}

		if (t)	// if not the last case
			sp.relief();
	}
	return 0;
}

