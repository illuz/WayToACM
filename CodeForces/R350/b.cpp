/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        b.cpp
*  Create Date: 2013-10-02 00:17:29
*  Descripton:  b 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define ms(a, i) memset(a, i, sizeof(a))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)

const int MAXN = 100010;
set<int> pre[MAXN], nex[MAXN];
int n, t, obj[MAXN], path[MAXN];
int d[MAXN], used[MAXN];
int Max = 0, rec;

int dp(int o) {
	if (d[o] != -1) return d[o];
	if (nex[o].size() > 1 || used[o]) return d[o] = 0;
	if (pre[o].size() == 0) {
		path[o] = 0;
		return d[o] = 1;
	}
	d[o] = 0;
	used[o] = 1;
	FI(i, pre[o]) {
		int ts = dp(*i);
		if (ts > d[o]) {
			d[o] = ts;
			path[o] = *i;
		}
	}
	return d[o] + 1;
}

void F(int p, int cnt) {
	if (p == 0) return;
	F(path[p], cnt + 1);
	if (cnt) printf("%d ", p);
	else printf("%d\n", p);
}

int main() {
	ms(d, -1);
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &obj[i + 1]);
	}
	rep(i, n) {
		scanf("%d", &t);
		if (t) {
			pre[i + 1].insert(t);
			nex[t].insert(i + 1);
		}
	}
	repf(i, 1, n) if (obj[i]) {
		t = dp(i);
		if (Max < t) {
			Max = t;
			rec = i;
		}
	}
	cout << Max << endl;
	F(rec, 0);
	return 0;
}
