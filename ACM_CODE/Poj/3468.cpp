/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3468.cpp
*  Create Date: 2014-08-08 15:53:07
*  Descripton:  segment tree
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)

typedef long long ll;

const int N = 100100;
const int ROOT = 1;

struct seg {
	ll w;
	ll flag;
};

struct segment_tree {
	seg node[N << 2];

	void update(int pos) {
		node[pos].w = node[lson(pos)].w + node[rson(pos)].w;
	}

	void build(int l, int r, int pos) {
		node[pos].flag = 0;
		if (l == r) {
			scanf("%lld", &node[pos].w);
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lson(pos));
		build(m + 1, r, rson(pos));
		update(pos);
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
	void modify(int l, int r, int pos, int x, int y, ll z) {
		if (x <= l && r <= y) {
			int len = r + 1 - l;
			node[pos].w += z * len;
			node[pos].flag += z;
			return;
		}
		push(l, r, pos);
		int m = (l + r) >> 1;
		if (x <= m)
			modify(l, m, lson(pos), x, y, z);
		if (y > m)
			modify(m + 1, r, rson(pos), x, y, z);
		update(pos);
	}

	// query the segment [x, y]
	ll query(int l, int r, int pos, int x, int y) {
		if (x <= l && r <= y)
			return node[pos].w;
		push(l, r, pos);
		int m = (l + r) >> 1;
		ll res = 0;
		if (x <= m)
			res += query(l, m, lson(pos), x, y);
		if (y > m)
			res += query(m + 1, r, rson(pos), x, y);
		return res;
	}

} sgm;

int n, q, ra, rb;
ll rc;
char op[3];

int main() {
	while (~scanf("%d%d", &n, &q)) {
		sgm.build(1, n, ROOT);
		while (q--) {
			scanf("%s", op);
			if (op[0] == 'Q') {
				scanf("%d%d", &ra, &rb);
				printf("%lld\n", sgm.query(1, n, ROOT, ra, rb));
			} else {
				scanf("%d%d%lld", &ra, &rb, &rc);
				sgm.modify(1, n, ROOT, ra, rb, rc);
			}
		}
	}
	return 0;
}

