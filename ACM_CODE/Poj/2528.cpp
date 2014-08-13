/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2528.cpp
*  Create Date: 2014-08-08 16:18:46
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

const int N = 50100;
const int ROOT = 1;

bool mp[N];
int t, n, r[N][2], tmp[N<<1], tcnt, ans, cnt;

struct seg {
	int w;
};

struct segment_tree {
	seg node[N << 2];

	void build(int l, int r, int pos) {
		if (l == r) {
			node[pos].w = 0;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lson(pos));
		build(m + 1, r, rson(pos));
	}

	void push(int l, int r, int pos) {
		seg& fa = node[pos];
		seg& lhs = node[lson(pos)];
		seg& rhs = node[rson(pos)];
		int len = r - l + 1;
		if (node[pos].w) {
			lhs.w = rhs.w = fa.w;
			fa.w = 0;
		}
	}

	// add the point [x,y] with z
	void modify(int l, int r, int pos, int x, int y, ll z) {
		if (x <= l && r <= y) {
			node[pos].w = z;
			return;
		}
		push(l, r, pos);
		int m = (l + r) >> 1;
		if (x <= m)
			modify(l, m, lson(pos), x, y, z);
		if (y > m)
			modify(m + 1, r, rson(pos), x, y, z);
	}

	// query the segment [x, y]
	void query(int l, int r, int pos) {
		if (node[pos].w) {
			if (mp[node[pos].w] == 0)
				ans++;
			mp[node[pos].w] = 1;
			return;
		}
		if (l == r) {
			return;
		}
		push(l, r, pos);
		int m = (l + r) >> 1;
		query(l, m, lson(pos));
		query(m + 1, r, rson(pos));
	}

} sgm;

int bins(int k) {
	int l = 0, r = cnt - 1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (tmp[m] == k)
			return m;
		if (tmp[m] < k)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		tcnt = 0;
		scanf("%d", &n);
		repf (i, 0, n - 1) {
			scanf("%d%d", &r[i][0], &r[i][1]);
			tmp[tcnt++] = r[i][0];
			tmp[tcnt++] = r[i][1];
		}
		sort(tmp, tmp + tcnt);

		cnt = 1;
		repf (i, 1, tcnt - 1) {
			if (tmp[i] != tmp[i - 1])
				tmp[cnt++] = tmp[i];
		}
		for (int i = cnt - 1; i > 0; i--) {
			if (tmp[i] != tmp[i - 1] + 1)
				tmp[cnt++] = tmp[i - 1] + 1;
		}
		sort(tmp, tmp + cnt);
		sgm.build(1, cnt, ROOT);

		repf (i, 0, n - 1) {
			int lhs = bins(r[i][0]) + 1;
			int rhs = bins(r[i][1]) + 1;
			sgm.modify(1, cnt, ROOT, lhs, rhs, i + 1);
		}

		ans = 0;
		memset(mp, 0, sizeof(mp));
		sgm.query(1, cnt, ROOT);
		printf("%d\n", ans);
	}
	return 0;
}
