/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-04-27 13:45:50
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 100010;

int n, k, a[N], head[N], am[N], used[N], fa[N], t, r, ans;
int cnt;
queue<int> q;

struct edge
{
	int v;
	int next;
} e[N * 2];

void addedge(int a, int b)
{
	e[cnt].v = b;
	e[cnt].next = head[a];
	head[a] = cnt++;
}

void bfs()
{
	while (!q.empty())
		q.pop();
	q.push(0);
	used[0] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = head[t]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if (!used[v]) {
				used[v] = 1;
				q.push(v);
				fa[v] = t;
			}
		}
	}
}

int main()
{
	memset(head, -1, sizeof(-1));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &am[i]);
		am[i]--;
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &t, &r);
		addedge(t - 1, r - 1);
		addedge(r - 1, t - 1);
	}
	bfs();
	memset(used, 0, sizeof(used));
	for (int i = 0; i < k; i++) {
		int u = am[i];
		if (used[u])
			continue;
		used[u] = 1;
		while (true) {
			if (u == 0 || used[fa[u]])
				break;
			ans += a[fa[u]];
			used[fa[u]] = 1;
			u = fa[u];
		}
	}
	printf("%d\n", ans);
	return 0;
}

