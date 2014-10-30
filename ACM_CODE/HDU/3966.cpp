/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3966.cpp
*  Create Date: 2014-10-21 20:14:07
*  Descripton:   
*/

#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define ROOT 1
#define N 50010

int fa[N], dep[N], siz[N], son[N], top[N], head[N], data[N];
struct Edge { int adj, next; } edge[N<<2];
struct seg { int l, r, w, flag; } node[N << 2];
int tree[N];
int tot;
int cnt;	// edge

int n, m, q, x, y, z;
char op[3];

inline void addedge(int u, int v) {
	edge[++cnt].adj = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

// there follows the segment updated version

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)

void update(int pos) {
	node[pos].w = node[lson(pos)].w + node[rson(pos)].w;
}

void build(int l, int r, int pos) {
	node[pos].l = l;
	node[pos].r = r;
	node[pos].flag = 0;
	node[pos].w = 0;
	if (l == r)
		return;
	int m = (l + r) >> 1;
	build(l, m, lson(pos));
	build(m + 1, r, rson(pos));
}

void push(int l, int r, int pos) {
	seg& fa = node[pos];
	seg& lhs = node[lson(pos)];
	seg& rhs = node[rson(pos)];
	int len = r - l + 1;
	if (fa.flag) {
		lhs.flag += fa.flag;
		rhs.flag += fa.flag;
		lhs.w += fa.flag * (len - (len >> 1));
		rhs.w += fa.flag * (len >> 1);
		fa.flag = 0;
	}
}

// add the point [x,y] with z
void modify(int pos, int x, int y, int z) {
	if (x <= node[pos].l && node[pos].r <= y) {
		int len = node[pos].r + 1 - node[pos].l;
		node[pos].w += z * len;
		node[pos].flag += z;
		return;
	}
	push(node[pos].l, node[pos].r, pos);
	int m = (node[pos].l + node[pos].r) >> 1;
	if (x <= m)
		modify(lson(pos), x, y, z);
	if (y > m)
		modify(rson(pos), x, y, z);
	update(pos);
}

// query the segment [x, y]
int query(int pos, int x, int y) {
	if (x <= node[pos].l && node[pos].r <= y)
		return node[pos].w;
	push(node[pos].l, node[pos].r, pos);
	int m = (node[pos].l + node[pos].r) >> 1;
	int res = 0;
	if (x <= m)
		res += query(lson(pos), x, y);
	if (y > m)
		res += query(rson(pos), x, y);
	return res;
}

// solve fa, dep, siz, son
void dfs1(int k, int f, int d) {
	dep[k] = d;
	fa[k] = f;
	siz[k] = 1;

	for (int i = head[k]; i; i = edge[i].next) {
		int adj = edge[i].adj;
		if (adj == f)
			continue;

		dfs1(adj, k, d + 1);

		siz[k] += siz[adj];
		if (!son[k] || siz[adj] > siz[son[k]])
			son[k] = adj;
	}
}

// solve top, tree
void dfs2(int k, int num) {
	top[k] = num;
	tree[k] = ++tot;

	if (!son[k])
		return;

	dfs2(son[k], num);
	int adj;
	for (int i = head[k]; i; i = edge[i].next) {
		adj = edge[i].adj;
		if (adj != son[k] && adj != fa[k])
			dfs2(adj, adj);
	}
}

void gao(int x, int y, int off) {
	int f1 = top[x], f2 = top[y];
	while (f1 != f2) {
		if (dep[f1] < dep[f2]) {
			swap(f1, f2);
			swap(x, y);
		}
		modify(ROOT, tree[f1], tree[x], off);
		x = fa[f1];
		f1 = top[x];
	}
	if (dep[x] < dep[y])
		modify(ROOT, tree[x], tree[y], off);
	else
		modify(ROOT, tree[y], tree[x], off);
}

int Scan() {
	int res = 0, ch, flag = 0;
	if((ch = getchar()) == '-')
		flag = 1;
	else if(ch >= '0' && ch <= '9')
		res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9' )
		res = res * 10 + ch - '0';
	return flag ? -res : res;
}

int main() {
	while (~scanf("%d%d%d", &n, &m, &q)) {
		tot = cnt = 0;
		repf (i, 1, n)
			data[i] = Scan();

		repf (i, 1, m) {
			x = Scan();
			y = Scan();
			addedge(x, y);
			addedge(y, x);
		}
		dfs1(1, 0, 1);
		dfs2(1, 1);
		build(1, tot, 1);
		while (q--) {
			scanf("%s", op);
			if (op[0] == 'I') {
				x = Scan();
				y = Scan();
				z = Scan();
				gao(x, y, z);
			} else if (op[0] == 'D') {
				x = Scan();
				y = Scan();
				z = Scan();
				gao(x, y, -z);
			} else {
				x = Scan();
				printf("%d\n", data[x] + query(ROOT, tree[x], tree[x]));
			}
		}
	}
	return 0;
}

