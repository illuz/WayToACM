/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        C.cpp
*  Create Date: 2014-08-21 00:51:33
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1e5 + 10;

ll n, m, w;
ll a[N], add[N];

bool check(int x) {
	ll sum = 0;
	memset(add, 0, sizeof(add));
	repf (i, 1, n) {
		add[i] += add[i - 1];
		if (a[i] + add[i] < x) {
			ll det = x - a[i] - add[i];
			if (i + w <= n) add[i + w] -= det;
			add[i] += det;
			sum += det;
		}
	}
	return sum <= m;
}

int main() {
	while (cin >> n >> m >> w) {
		repf (i, 1, n)
			cin >> a[i];
		ll l = 1, r = 2e9, ans = 1;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}
		cout << ans << endl;
	}
	return 0;
}

