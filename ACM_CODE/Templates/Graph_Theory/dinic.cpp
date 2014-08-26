/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        dinic.cpp
*  Create Date: 2014-08-25 09:13:44
*  Descripton:  dinic 
*/

#include <bits/stdc++.h>
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
}

int main() {

	return 0;
}

