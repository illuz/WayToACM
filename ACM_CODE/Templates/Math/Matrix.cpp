/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        Matrix.cpp
*  Create Date: 2014-07-31 10:35:19
*  Descripton:  Matrix template 
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 20;
const int SIZE = 32;		// max size of the matrix
const int MOD = 2008;

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
} a, b, c;

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

// 二分求和
Mat calc(Mat a, int n) {
	if (n == 1)
		return a;
	if (n&1)
		return (a^n) + calc(a, n - 1);
	else
		return calc(a, n/2) * ((a^(n/2)) + 1);
}

int main() {

	return 0;
}

