/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3264.cpp
*  Create Date: 2014-08-05 00:15:22
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
	ll mmax;
	ll mmin;
};

struct segment_tree { 
	seg node[N << 2];

	void update(int pos) {
		node[pos].mmax = max(node[lson(pos)].mmax, node[rson(pos)].mmax);
		node[pos].mmin = min(node[lson(pos)].mmin, node[rson(pos)].mmin);
	}

	void build(int l, int r, int pos) {
		if (l == r) {
			scanf("%lld", &node[pos].mmin);
			node[pos].mmax = node[pos].mmin;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lson(pos));
		build(m + 1, r, rson(pos));
		update(pos);
	}

	// query the segment [x, y]
	ll query(int l, int r, int pos, int x, int y, bool ismax) {
		if (x <= l && r <= y) {
			return ismax ? node[pos].mmax : node[pos].mmin;
		}
		int m = (l + r) >> 1;
		ll res = ismax ? 0 : 1e6 + 1;
		if (x <= m)
			res = query(l, m, lson(pos), x, y, ismax);
		if (y > m) {
			res = ismax ? max(res, query(m + 1, r, rson(pos), x, y, ismax)) :
				min(res, query(m + 1, r, rson(pos), x, y, ismax));
		}
		return res;
	}
} sgm;

int n, q, l, r;

int main() {
	while (~scanf("%d%d", &n, &q)) {
		sgm.build(1, n, ROOT);
		while (q--) {
			scanf("%d%d", &l, &r);
			printf("%lld\n", sgm.query(1, n, ROOT, l, r, 1) - sgm.query(1, n, ROOT, l, r, 0));
		}
	}
	return 0;
}

