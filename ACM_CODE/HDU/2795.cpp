/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2795.cpp
*  Create Date: 2014-08-05 16:12:47
*  Descripton:  segment tree 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)

typedef long long ll;

const int N = 200010;
const int ROOT = 1;

int h, w, n, t;

// below is sement point updated version
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
			node[pos].w = w;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lson(pos));
		build(m + 1, r, rson(pos));
		update(pos);
	}

	int queryandmodify(int l, int r, int pos, ll y) {
		if (y > node[pos].w) {
			return -1;
		}
		if (l == r) {
			node[pos].w -= y;
			return l;
		}
		int m = (l + r) >> 1;
		int res;
		if (y <= node[lson(pos)].w)
			res = queryandmodify(l, m, lson(pos), y);
		else
			res = queryandmodify(m + 1, r, rson(pos), y);
		update(pos);
		return res;
	}

} sgm;

int main() {
	while (~scanf("%d%d%d", &h, &w, &n)) {
		h = min(h, n);
		sgm.build(1, h, ROOT);
		repf (i, 1, n) {
			scanf("%d", &t);
			printf("%d\n", sgm.queryandmodify(1, h, ROOT, t));
		}
	}
	return 0;
}

