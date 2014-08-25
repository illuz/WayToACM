/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1459_dinic.cpp
*  Create Date: 2014-08-25 09:58:18
*  Descripton:  network flow
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;
const int N = 150;		// points
const int M = 20500;	// edges
const ll INF = 1ll<<62;

struct Edge {
	int from;
	int to;
	int next;
	ll cap;
} edge[M];

int D[N];
int head[N];
int tot;

void addedge(int u, int v, ll w) {
	edge[tot].from = u;
	edge[tot].to = v;
	edge[tot].cap = w;
	edge[tot].next = head[u];
	head[u] = tot++;
	edge[tot].from = v;
	edge[tot].to = u;
	edge[tot].cap = 0;		// if undirect, 0 -> w
	edge[tot].next = head[v];
	head[v] = tot++;
}

bool BFS(int S, int T) {
	int Q[N];
	int op = 0, ed = 0;
	memset(D, -1, sizeof(D));
	Q[ed++] = S;
	D[S] = 0;
	while (op < ed) {
		int u = Q[op++];
		if (op == N) op = 0;
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if (edge[i].cap > 0 && D[v] == -1) {
				D[v] = D[u] + 1;
				Q[ed++] = v;
				if (ed == N) ed = 0;
				if (v == T)
					return true;
			}
		}
	}
	return false;
}

ll dinic(int S, int T) {
	ll res = 0;
	int top;
	int stack[N], cur[N];
	while (BFS(S, T)) {
		memcpy(cur, head, sizeof(head));
		int u = S;
		top = 0;
		while (1) {
			if (u == T) {
				ll min = INF;
				int loc;
				repf (i, 0, top - 1) {
					if (min > edge[stack[i]].cap) {
						min = edge[stack[i]].cap;
						loc = i;
					}
				}
				repf (i, 0, top - 1) {
					edge[stack[i]].cap -= min;
					edge[stack[i]^1].cap += min;	// because the edges are couples
				}
				res += min;
				top = loc;
				u = edge[stack[top]].from;
			}
			for (int &i = cur[u]; i != -1; i = edge[i].next) {
				if (edge[i].cap != 0 && D[u] + 1 == D[edge[i].to])
					break;
			}
			if (cur[u] != -1) {
				stack[top++] = cur[u];
				u = edge[cur[u]].to;
			} else {
				if (top == 0)
					break;
				D[u] = -1;
				u = edge[stack[--top]].from;
			}
		}
	}
	return res;
}

int n, m, sn, tn, u, v;
ll w;

void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
	// read
	while (m--) {
		while (getchar() != '(');
		scanf("%d,%d)%lld", &u, &v, &w);
		addedge(u + 1, v + 1, w);
	}
	while (sn--) {
		while (getchar() != '(');
		scanf("%d)%lld", &u, &w);
		addedge(0, u + 1, w);
	}
	while (tn--) {
		while (getchar() != '(');
		scanf("%d)%lld", &u, &w);
		addedge(u + 1, n + 1, w);
	}
}

int main() {
	while (~scanf("%d%d%d%d", &n, &sn, &tn, &m)) {
		init();
		printf("%lld\n", dinic(0, n + 1));
	}
	return 0;
}

