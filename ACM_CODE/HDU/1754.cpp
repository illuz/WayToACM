/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1754.cpp
*  Create Date: 2014-08-05 09:46:17
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

const int N = 200100;
const int ROOT = 1;

// below is sement point updated
struct seg {
	ll w;
};

struct segment_tree { 
	seg node[N << 2];

	void update(int pos) {
		node[pos].w = max(node[lson(pos)].w, node[rson(pos)].w);
	}

	void build(int l, int r, int pos) {
		if (l == r) {
			scanf("%lld", &node[pos].w);
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lson(pos));
		build(m + 1, r, rson(pos));
		update(pos);
	}

	void modify(int l, int r, int pos, int x, ll y) {
		if (l == r) {
			node[pos].w = y;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m)
			modify(l, m, lson(pos), x, y);
		else
			modify(m + 1, r, rson(pos), x, y);
		update(pos);
	}

	// query the segment [x, y]
	ll query(int l, int r, int pos, int x, int y) {
		if (x <= l && r <= y)
			return node[pos].w;
		int m = (l + r) >> 1;
		ll res = 0;
		if (x <= m)
			res = max(res, query(l, m, lson(pos), x, y));
		if (y > m)
			res = max(res, query(m + 1, r, rson(pos), x, y));
		return res;
	}
} sgm;

int n, m, a, b;
char op[3];

int main() {
	while (~scanf("%d%d", &n, &m)) {
		sgm.build(1, n, ROOT);
		while (m--) {
			scanf("%s%d%d", op, &a, &b);
			if (op[0] == 'U') {
				sgm.modify(1, n, ROOT, a, b);
			} else {
				printf("%d\n", sgm.query(1, n, ROOT, a, b));
			}
		}
	}
	return 0;
}

