/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2842.cpp
*  Create Date: 2014-08-03 22:22:57
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 31;
const int SIZE = 3;	// max size of the matrix
const int MOD = 200907;

struct Mat{
	int n;
	ll v[SIZE][SIZE];	// value of matrix

	Mat(int _n = SIZE) {
		n = _n;
		memset(v, 0, sizeof(v));
	}

	void init(ll _v) {
		memset(v, 0, sizeof(v));
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

Mat operator*(Mat a, Mat b) {
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
		if (k&1) c = c * a;
		a = a * a;
		k >>= 1;
	}
	return c;
}

ll solve(int n) {
	if (n <= 2) {
		return n;
	}
	// init
	a.v[0][1] = 2;
	a.v[0][0] = a.v[0][2] = a.v[1][0] = a.v[2][2] = 1;
	b.v[0][0] = 2;
	b.v[1][0] = b.v[2][0] = 1;
	
	c = a ^ (n - 2);
	c = c * b;
	return c.v[0][0];
}

int main() {
	int n;
	while (~scanf("%d", &n) && n) {
		cout << solve(n) << endl;
	}
	return 0;
}

