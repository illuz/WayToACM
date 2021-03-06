/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        01.cpp
*  Create Date: 2014-08-25 15:41:53
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

int dep[N];
int head[N];
int tot;

int n, m, u, v;

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
	memset(dep, -1, sizeof(dep));
	Q[ed++] = S;
	dep[S] = 0;
	while (op < ed) {
		int u = Q[op++];
		if (op == N) op = 0;
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if (edge[i].cap > 0 && dep[v] == -1) {
				dep[v] = dep[u] + 1;
				Q[ed++] = v;
				if (ed == N) ed = 0;
				if (v == T)
					return true;
			}
		}
	}
	return false;
}

ll DICNIC(int S, int T) {
	ll res = 0;
	int top;
	int stack[N], cur[N];
	while (BFS(S, T)) {
		memcpy(cur, head, sizeof(head));
		int u = S;
		top = 0;
		while (1) {
			if (u == T) {
				ll tmp = INF;
				int loc;
				repf (i, 0, top - 1) {
					if (tmp > edge[stack[i]].cap) {
						tmp = edge[stack[i]].cap;
						loc = i;
					}
				}
				repf (i, 0, top - 1) {
					edge[stack[i]].cap -= tmp;
					edge[stack[i]^1].cap += tmp;	// because the edges are couples
				}
				res += tmp;
				top = loc;
				u = edge[stack[top]].from;
			}
			for (int &i = cur[u]; i != -1; i = edge[i].next) {
				if (edge[i].cap != 0 && dep[u] + 1 == dep[edge[i].to])
					break;
			}
			if (cur[u] != -1) {
				stack[top++] = cur[u];
				u = edge[cur[u]].to;
			} else {
				if (top == 0)
					break;
				dep[u] = -1;
				u = edge[stack[--top]].from;
			}
		}
	}
	return res;
}

void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
	// read
	scanf("%d%d", &m, &n);
	repf (i, 1, m) addedge(0, i, 1);
	repf (i, m + 1, n) addedge(i, n + 1, 1);
	bool rec[N][N] = {0};
	while (scanf("%d%d", &u, &v) && u != -1) {
		if (rec[u][v] == 0) {
			addedge(u, v, 1);
			rec[u][v] = 1;
		}
	}
}

int main() {
	init();
	ll ans = DICNIC(0, n + 1);
	if (ans) {
		printf("%lld\n", ans);
		repf (i, 0, tot - 1) {
			if (edge[i].from != 0 && edge[i].to != n + 1 && edge[i].from < edge[i].to && edge[i].cap == 0) {
				printf("%d %d\n", edge[i].from, edge[i].to);
			}
		}
	} else {
		printf("No Solution!");
	}
	return 0;
}

