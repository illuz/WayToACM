/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1588.cpp
*  Create Date: 2014-08-04 16:13:51
*  Descripton:  Matrix
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 20;
const int SIZE = 2;		// max size of the matrix

ll MOD;
ll k, b, n;

struct Mat{
	int n;
	ll v[SIZE][SIZE];	// value of matrix

	Mat(int _n = SIZE) {
		n = _n;
	}

	void init(ll _v = 0) {
		memset(v, 0, sizeof(v));
		if (_v)
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
} a, B, C;

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

Mat operator + (Mat a, Mat b) {
	Mat c(a.n);
	repf (i, 0, a.n - 1)
		repf (j, 0, a.n - 1)
			c.v[i][j] = (b.v[i][j] + a.v[i][j]) % MOD;
	return c;
}

Mat operator + (Mat a, ll b) {
	Mat c = a;
	repf (i, 0, a.n - 1)
		c.v[i][i] = (a.v[i][i] + b) % MOD;
	return c;
}

// 二分求和1..n
Mat calc(Mat a, int n) {
	if (n == 1)
		return a;
	if (n&1)
		return (a^n) + calc(a, n - 1);
	else
		return calc(a, n/2) * ((a^(n/2)) + 1);
}

int main() {
	a.init();
	a.v[0][0] = a.v[0][1] = a.v[1][0] = 1;
	while (~scanf("%lld%lld%lld%lld", &k, &b, &n, &MOD)) {
		B = (a^k);
		C = calc(B, n - 1) + (a^0);
		C = (a^b) * C;
		printf("%lld\n", C.v[0][1]);
	}
	return 0;
}

