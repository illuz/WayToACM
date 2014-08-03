/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1575.cpp
*  Create Date: 2014-08-03 08:50:20
*  Descripton:  matrix quick pow
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>
#include <cstdlib>
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 0;
const int SIZE = 11;
const int MOD = 9973;

int t, n, k;

struct Mat{
	int n;
	ll v[SIZE][SIZE];	// value of matrix

	Mat(int _n = SIZE) {
		n = _n;
		memset(v, 0, sizeof(v));
	}

	void init(ll _v) {
		repf (i, 0, n)
			v[i][i] = _v;
	}
} a;

Mat operator * (Mat a, Mat b) {
	Mat c(a.n);
	repf (i, 0, n - 1) {
		repf (j, 0, n - 1) {
			c.v[i][j] = 0;
			repf (k, 0, n - 1) {
				c.v[i][j] += (a.v[i][k] * b.v[k][j]) % MOD;
				c.v[i][j] %= MOD;
			}
		}
	}
	return c;
}

Mat operator ^ (Mat a, ll k) {
	Mat c(a.n);
	c.init(1);
	while (k) {
		if (k&1) c = a * c;
		a = a * a;
		k >>= 1;
	}
	return c;
}

void read() {
	scanf("%d%d", &n, &k);
	a.n = n;

	repf (i, 0, n - 1)
		repf (j, 0, n - 1) {
			scanf("%lld", &a.v[i][j]);
		}
}

void solve() {
	Mat b = a ^ k;
	ll res = 0;
	repf (i, 0, n - 1) {
		res += b.v[i][i];
		res %= MOD;
	}
	printf("%lld\n", res);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		read();
		solve();
	}
	return 0;
}
