/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1459_sap.cpp
*  Create Date: 2014-08-25 15:07:30
*  Descripton:  sap
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
int gap[N];
int head[N];
int tot;

int n, m, sn, tn, u, v;
ll w;

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
	memset(gap, 0, sizeof(gap));
	Q[ed++] = T;
	dep[T] = 0;
	gap[0] = 1;
	while (op < ed) {
		int u = Q[op++];
		if (op == N) op = 0;
		for (int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if (edge[i].cap == 0 && dep[v] == -1) {
				dep[v] = dep[u] + 1;
				++gap[dep[v]];
				Q[ed++] = v;
				if (ed == N) ed = 0;
			}
		}
	}
	return false;
}

ll SAP(int S, int T) {
	BFS(S, T);

	ll res = 0;
	int top = 0;
	int stack[N], cur[N];
	memcpy(cur, head, sizeof(head));
	int u = S;

	while (dep[S] < n) {
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

		if (u != T && gap[dep[u] - 1] == 0)
			break;

		int i;
		for (i = cur[u]; i != -1; i = edge[i].next) {
			if (edge[i].cap != 0 && dep[u] == dep[edge[i].to] + 1)
				break;
		}
		if (i != -1) {
			cur[u] = i;
			stack[top++] = i;
			u = edge[i].to;
		} else {
			int mmin = n;
			for (int i = head[u]; i != -1; i = edge[i].next) {
				if (edge[i].cap == 0) continue;
				if (mmin > dep[edge[i].to]) {
					mmin = dep[edge[i].to];
					cur[u] = i;
				}
			}
			gap[dep[u]]--;
			dep[u] = mmin + 1;
			gap[dep[u]]++;
			if (u != S)
				u = edge[stack[--top]].from;
		}
	}
	return res;
}



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
		int end = n + 1;
		n += 2;
		printf("%lld\n", SAP(0, end));
	}
	return 0;
}

