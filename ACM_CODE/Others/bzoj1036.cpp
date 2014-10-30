/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1036.cpp
*  Create Date: 2014-10-21 15:27:22
*  Descripton:   
*/

// #pragma comment(linker, "/STACK:100000000, 100000000")
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 30010;
const int INF = 0x7fffffff;

int fa[N], dep[N], siz[N], son[N], top[N];
int w[N];

int head[N], data[N];

int n, q, x, y;
char op[10];

struct Node {
	int l;
	int r;
	int sum;
	int max;
} seg[N<<2];
int tree[N<<2], eert[N<<2];		// node->segtree, segtree->node
int tot;	// number of segtree

struct Edge {
	int adj;
	int next;
} edge[N<<1];
int cnt;	// edge

inline void addedge(int u, int v) {
	edge[++cnt].adj = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
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

// solve top, tree, eert
void dfs2(int k, int num) {
	top[k] = num;
	tree[k] = ++tot;
	eert[tot] = k;

	if (!son[k])
		return;

	dfs2(son[k], num);
	for (int i = head[k]; i; i = edge[i].next) {
		int adj = edge[i].adj;
		if (adj != son[k] && adj != fa[k])
			dfs2(adj, adj);
	}
}

// build segment tree
void build(int k, int l, int r) {
	seg[k].l = l;
	seg[k].r = r;
	if (l == r) {
		seg[k].sum = seg[k].max = data[eert[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build((k << 1) + 1, mid + 1, r);
	seg[k].sum = seg[k<<1].sum + seg[(k<<1)+1].sum;
	seg[k].max = max(seg[k<<1].max, seg[(k<<1)+1].max);
}

void update(int k, int pos) {
	if (seg[k].l == seg[k].r) {
		seg[k].sum = seg[k].max = data[eert[pos]];
		return;
	}
	int mid = (seg[k].l + seg[k].r) >> 1;
	if (pos <= mid)
		update(k<<1, pos);
	else
		update((k<<1) + 1, pos);
	seg[k].sum = seg[k<<1].sum + seg[(k<<1)+1].sum;
	seg[k].max = max(seg[k<<1].max, seg[(k<<1)+1].max);
}

int query_sum(int k, int l, int r) {
	if (seg[k].l >= l && seg[k].r <= r)
		return seg[k].sum;
	int mid = (seg[k].l + seg[k].r) >> 1, ret = 0;
	if (l <= mid)
		ret += query_sum(k << 1, l, r);
	if (r > mid)
		ret += query_sum((k<<1) + 1, l, r);
	return ret;
}

int query_max(int k, int l, int r) {
	if (seg[k].l >= l && seg[k].r <= r)
		return seg[k].max;
	int mid = (seg[k].l + seg[k].r) >> 1, ret = -INF;
	if (l <= mid)
		ret = query_max(k << 1, l, r);
	if (r > mid)
		ret = max(ret, query_max((k<<1) + 1, l, r));
	return ret;
}

// find the sum in path x->y
int find_sum(int x, int y) {
	int f1 = top[x], f2 = top[y];
	int ans = 0;
	while (f1 != f2) {
		if (dep[f1] < dep[f2]) {
			swap(f1, f2);
			swap(x, y);
		}
		ans += query_sum(1, tree[f1], tree[x]);
		x = fa[f1];
		f1 = top[x];
	}
	if (dep[x] <= dep[y])
		return ans + query_sum(1, tree[x], tree[y]);
	else
		return ans + query_sum(1, tree[y], tree[x]);
}

// find the max in path x->y
int find_max(int x, int y) {
	int f1 = top[x], f2 = top[y];
	int ans = -INF;
	while (f1 != f2) {
		if (dep[f1] < dep[f2]) {
			swap(f1, f2);
			swap(x, y);
		}
		ans = max(ans, query_max(1, tree[f1], tree[x]));
		x = fa[f1];
		f1 = top[x];
	}
	if (dep[x] <= dep[y])
		return max(ans, query_max(1, tree[x], tree[y]));
	else
		return max(ans, query_max(1, tree[y], tree[x]));
}

int main() {
	scanf("%d", &n);
	repf (i, 1, n - 1) {
		scanf("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	repf (i, 1, n)
		scanf("%d", &data[i]);
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	scanf("%d", &q);
	while (q--) {
		scanf("%s%d%d", op, &x, &y);
		if (op[0] == 'C') {
			data[x] = y;
			update(1, tree[x]);
		} else if (op[1] == 'M')
			printf("%d\n", find_max(x, y));
		else
			printf("%d\n", find_sum(x, y));
	}
	return 0;
}

