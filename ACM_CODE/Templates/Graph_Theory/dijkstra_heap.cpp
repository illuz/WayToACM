/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3013.cpp
*  Create Date: 2014-07-27 09:54:35
*  Descripton:  dijkstra 
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 50100;
const long long INF = (long long)(1<<16)*N;

struct Edge {
	int from, to;
	int dist;
};

struct HeapNode {
	int d;
	int u;
	bool operator < (const HeapNode rhs) const {
		return d > rhs.d;
	}
};

struct Dijkstra {
	int n, m;			// number of nodes and edges
	vector<Edge> edges;
	vector<int> G[N];	// graph
	bool vis[N];	// visited?
	long long d[N];		// dis
	int p[N];		// prevent edge

	void init(int _n) {
		n = _n;
	}

	void relief() {
		for (int i = 0; i < n; i++) {
			G[i].clear();
		}
		edges.clear();
	}

	void AddEdge(int from, int to, int dist) {
		// if non-directed, add twice
		edges.push_back((Edge){from, to, dist});
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s) {
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++) {
			d[i] = INF;
			vis[i] = 0;
		}
		d[s] = 0;

		Q.push((HeapNode){0, s});
		while (!Q.empty()) {
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if (vis[u]) {
				continue;
			}
			vis[u] = true;
			for (int i = 0; i < G[u].size(); i++) {	// update the u's linking nodes
				Edge& e = edges[G[u][i]];	//ref for convenient
				if (d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push((HeapNode){d[e.to], e.to});
				}
			}
		}
	}
};

int t;
int e, v, x, y, d, w[N];

int main() {
	scanf("%d", &t);
	Dijkstra di;

	while (t--) {
		scanf("%d%d", &v, &e);
		di.init(v);

		repf (i, 0, v - 1) {
			scanf("%d" ,&w[i]);
		}
		repf (i, 0, e - 1) {
			scanf("%d%d%d", &x, &y, &d);
			di.AddEdge(x - 1, y - 1, d);
			di.AddEdge(y - 1, x - 1, d);
		}
		di.dijkstra(0);

		long long ans = 0;
		bool ring = false;
		repf (i, 0, v - 1) {
			if (di.d[i] == INF) {
				ring = true;
			}
			ans += w[i] * di.d[i];
		}
		if (ring) {
			cout << "No Answer" << endl;
		} else {
			cout << ans << endl;
		}

		if (t)	// if not the last case
			di.relief();
	}
	return 0;
}

