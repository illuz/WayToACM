/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1166.cpp
*  Create Date: 2014-08-04 23:52:52
*  Descripton:   
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

const int N = 50000;
const int ROOT = 1;

// below is sement point updated
struct seg {
	ll w;
};

struct segment_tree { 
	seg node[N << 2];

	void update(int pos) {
		node[pos].w = node[lson(pos)].w + node[rson(pos)].w;
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

	// add the point x with y
	void modify(int l, int r, int pos, int x, ll y) {
		if (l == r) {
			node[pos].w += y;
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
			res += query(l, m, lson(pos), x, y);
		if (y > m)
			res += query(m + 1, r, rson(pos), x, y);
		return res;
	}
} sgm;

int t, n, a;
ll b;
char op[10];

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		printf("Case %d:\n", cas);
		scanf("%d", &n);
		sgm.build(1, n, ROOT);
		while (~scanf("%s", op) && op[0] != 'E') {
			scanf("%d%lld", &a, &b);
			if (op[0] == 'A') {
				sgm.modify(1, n, ROOT, a, b);
			} else if (op[0] == 'S') {
				sgm.modify(1, n, ROOT, a, -b);
			} else {
				printf("%lld\n", sgm.query(1, n, ROOT, a, (int)b));
			}
		}
	}
	return 0;
}

