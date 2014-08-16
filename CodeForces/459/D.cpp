/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-08-16 00:18:08
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)

const int N = 1e6 + 10;

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
			node[pos].w = 0;
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

ll t, a[N];
int s1[N], s2[N];

map<ll, int> mp;

int main() {
	while (cin >> t) {
		mp.clear();
		rep (i, t) {
			cin >> a[i];
			mp[a[i]]++;
			s1[i] = mp[a[i]];
		}
		mp.clear();
		for (int i = t - 1; i >= 0; i--) {
			mp[a[i]]++;
			s2[i] = mp[a[i]];
		}
		sgm.build(1, t, ROOT);
		ll ans = 0;
		rep (i, t) {
			ans += sgm.query(1, t, ROOT, s2[i] + 1, t); 
			sgm.modify(1, t, ROOT, s1[i], 1);
			//cout << s1[i] << ' ' << s2[i] << ' ' << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}

