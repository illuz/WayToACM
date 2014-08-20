/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3333.cpp
*  Create Date: 2014-08-20 20:14:20
*  Descripton:  block
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef __int64 ll;

const int N = 1e5 + 10;

struct Query {
	int l;
	int r;
	int id;
	int b_id;
	bool operator <(const Query &b) const {
		return b_id < b.b_id || (b_id == b.b_id && r < b.r);
	}
} Q[N];

int t, n, m, L, R, b_size, cnt;
ll sum, ans[N];
int app[N], Hash[N], data[N];
map<int, int> mp;

void update(int l, int r, int id) {
	for (int i = L; i < l; i++) {
		app[Hash[i]]--;
		if (!app[Hash[i]])
			sum -= data[i];
	}
	for (int i = R + 1; i <= r; i++) {
		if (!app[Hash[i]])
			sum += data[i];
		app[Hash[i]]++;
	}
	for (int i = L - 1; i >= l; i--) {
		if (!app[Hash[i]])
			sum += data[i];
		app[Hash[i]]++;
	}
	for (int i = R; i > r; i--) {
		app[Hash[i]]--;
		if (!app[Hash[i]])
			sum -= data[i];
	}
	L = l;
	R = r;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		b_size = sqrt(n + 1e-8);
		cnt = 0;
		mp.clear();

		repf (i, 1, n) {
			scanf("%d", &data[i]);
			if (mp[data[i]] == 0) mp[data[i]] = ++cnt;
			Hash[i] = mp[data[i]];
		}

		scanf("%d", &m);
		repf (i, 1, m) {
			scanf("%d%d", &Q[i].l, &Q[i].r);
			Q[i].b_id = Q[i].l / b_size;
			Q[i].id = i;
		}

		sort(Q + 1, Q + m + 1);

		sum = 0;
		memset(app, 0, sizeof(app));
		repf (i, Q[1].l, Q[1].r) {
			if (!app[Hash[i]]) {
				sum += data[i];
			}
			app[Hash[i]]++;
		}
		ans[Q[1].id] = sum;
		L = Q[1].l;
		R = Q[1].r;

		repf (i, 2, m) {
			update(Q[i].l, Q[i].r, i);
			ans[Q[i].id] = sum;
		}

		repf (i, 1, m) {
			printf("%I64d\n", ans[i]);
		}
	}
	return 0;
}

