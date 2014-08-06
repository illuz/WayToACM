/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        Sement_tree.cpp
*  Create Date: 2014-08-04 23:31:46
*  Descripton:  Template of segment tree, modified from windalex
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


// below is sement point updated version
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

	// remove the point that the sum of [0, it] is x, return its id
	int remove(int l, int r, int pos, ll x) {
		if (l == r) {
			node[pos].w = 0;
			return l;
		}
		int m = (l + r) >> 1;
		int res;
		if (x < node[lson(pos)].w)
			res = remove(l, m, lson(pos), x);
		else
			res = remove(m + 1, r, rson(pos), x - node[lson(pos)].w);
		update(pos);
		return res;
	}
} sgm;



// there follows the segment updated version

struct seg {
	bool w;
	int flag;
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
			ls.flag += fa.flag;
			rs.flag += fa.flag;
			ls.w += fa.flag * (len - (len >> 1));
			rs.w += fa.flag * (len >> 1);
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
		int m = (l + r) >> 1;
		ll res = 0;
		if (x <= m)
			res += query(l, m, lson(pos), x, y);
		if (y > m)
			res += query(m + 1, r, rson(pos), x, y);
		return res;
	}

} sgm;

int main() {

	return 0;
}

