/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3507.cpp
*  Create Date: 2014-09-19 10:19:57
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 5e6 + 10;

int n, m, l, r, q[N];
ll s[N], x[N], y[N], k[N];

void init() {
	int x;
	repf (i, 1, n) {
		cin >> x;
		s[i] = s[i - 1] + x;
		k[i] = s[i] * 2;
	}
}

inline bool check(int a, int b, int c) {
	return (y[a] - y[b]) * (k[b] - k[c]) <= (y[b] - y[c]) * (k[a] - k[b]);
}

void solve() {
	q[0] = l = r = 0;
	repf (i, 1, n) {
		while (l < r && (y[q[l+1]]-y[q[l]]) <= s[i] * (k[q[l+1]]-k[q[l]]))
			l++;
		x[i] = x[q[l]] + (s[i] - s[q[l]]) * (s[i] - s[q[l]]) + m;
		y[i] = x[i] + s[i] * s[i];
		while (l < r && check(i, q[r], q[r-1]))
			r--;
		q[++r] = i;
	}
	cout << x[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	while (cin >> n >> m) {
		init();
		solve();
	}
	return 0;
}

