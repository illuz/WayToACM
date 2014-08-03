/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        Matrix.cpp
*  Create Date: 2014-07-31 10:35:19
*  Descripton:  Matrix template 
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

int main() {
	Mat a, b, c;

	return 0;
}

