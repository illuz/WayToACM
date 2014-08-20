/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        4391.cpp
*  Create Date: 2014-08-20 10:36:28
*  Descripton:  Hash Block
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1e5 + 5;
const int B_SIZE = int(sqrt(N + 1e8) + 10);

int n, m, bsize, bnum;
int dt[N];	// data
int q, l, r, c;

struct HashBlock {
	int lazy;		// lazy flag
	int size;		// the size of this block
	map<int, int> mp;	// the result to be query
} b[B_SIZE];

void init(int n) {
	bsize = sqrt(n + 1e-8);
	bnum = (n-1) / bsize + 1;

	repf (i, 0, bnum - 1) {
		b[i].lazy = -1;
		b[i].size = bsize;
		b[i].mp.clear();
	}
	b[bnum - 1].size = n - ((bnum-1) * bsize);
}

// push down if whole block is the same
void pushdown(int id) {
	HashBlock &hb = b[id];
	if (hb.lazy != -1) {
		repf (i, id*bsize, id*bsize + hb.size - 1) {
			dt[i] = hb.lazy;
		}
		hb.mp.clear();
		hb.mp[hb.lazy] = hb.size;
		hb.lazy = -1;
	}
}

void update(int l, int r, int c) {
	int lb = l / bsize, rb = r / bsize;
	// mark the middle blocks
	repf (i, lb + 1, rb - 1)
		b[i].lazy = c;

	// left and right
	if (lb != rb) {
		pushdown(lb);
		pushdown(rb);
		repf (i, l, lb*bsize + b[lb].size - 1) {
			b[lb].mp[dt[i]]--;
			b[lb].mp[c]++;
			dt[i] = c;
		}
		repf (i, rb*bsize, r) {
			b[rb].mp[dt[i]]--;
			b[rb].mp[c]++;
			dt[i] = c;
		}
	} else {
		pushdown(lb);
		repf (i, l, r) {
			b[lb].mp[dt[i]]--;
			b[lb].mp[c]++;
			dt[i] = c;
		}
	}
}

int query(int l, int r, int c) {
	int lb = l / bsize, rb = r / bsize, ans = 0;
	// middle
	repf (i, lb + 1, rb - 1) {
		if (b[i].lazy == c)
			ans += b[i].size;
		else if (b[i].lazy == -1 && b[i].mp.find(c) != b[i].mp.end()) {
			ans += b[i].mp[c];
		}
	}

	// left and right
	if (lb != rb) {
		pushdown(lb);
		pushdown(rb);
		repf (i, l, lb*bsize + b[lb].size - 1) {
			ans += (dt[i] == c);
		}
		repf (i, rb*bsize, r) {
			ans += (dt[i] == c);
		}
	} else {
		pushdown(lb);
		repf (i, l, r) {
			ans += (dt[i] == c);
		}
	}
	return ans;
}

void read() {
	repf (i, 0, n - 1) {
		scanf("%d", &dt[i]);
		b[i/bsize].mp[dt[i]]++;
	}
}

void solve() {
	while (m--) {
		scanf("%d%d%d%d", &q, &l, &r, &c);
		if (q == 1)
			update(l, r, c);
		else
			printf("%d\n", query(l, r, c));
	}
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		init(n);
		read();
		solve();
	}
	return 0;
}

