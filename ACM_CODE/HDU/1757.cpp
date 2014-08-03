/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1757.cpp
*  Create Date: 2014-08-03 09:24:45
*  Descripton:  Matrix quick power 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 20;
const int SIZE = 20;		// max size of the matrix

ll k, MOD;

struct Mat{
	int n;
	ll v[SIZE][SIZE];	// value of matrix

	Mat(int _n = SIZE) {
		n = _n;
		memset(v, 0, sizeof(v));
	}

	void init(ll _v) {
		repf (i, 0, n - 1)
			v[i][i] = _v;
	}

	void output() {
		repf (i, 0, n - 1) {
			repf (j, 0, n - 1)
				printf("%lld ", v[i][j]);
			puts("");
		}
		puts("");
	}
} a, b;

Mat operator * (Mat a, Mat b) {
	Mat c(a.n);
	repf (i, 0, a.n - 1) {
		repf (j, 0, a.n - 1) {
			c.v[i][j] = 0;
			repf (k, 0, a.n - 1) {
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

void init() {
	// init
	repf (i, 0, 9)
		a.v[9 - i][0] = i;
	repf (i, 0, 8)
		b.v[i + 1][i] = 1;
}

void solve() {
	// read
	repf (i, 0, 9)
		scanf("%lld", &b.v[0][i]);

	Mat c;
	if (k <= 9) {
		printf("%lld\n", k % MOD);
	} else {
		c = b ^ (k - 9);
//		c.output();
		c = c * a;
		printf("%lld\n", c.v[0][0] % MOD);
	}
}

int main() {
	init();
	while (~scanf("%lld%lld", &k, &MOD)) {
		solve();
	}
	return 0;
}

