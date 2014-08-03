/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2604.cpp
*  Create Date: 2014-08-02 21:20:18
*  Descripton:  matrix 
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
const int SIZE = 4;

int l, MOD;

struct Mat{
	ll v[SIZE][SIZE];	// value of matrix

	Mat() {
		memset(v, 0, sizeof(v));
	}

	void init(ll _v) {
		repf (i, 0, SIZE)
			v[i][i] = _v;
	}
};

Mat operator * (Mat a, Mat b) {
	Mat c;
	repf (i, 0, SIZE - 1) {
		repf (j, 0, SIZE - 1) {
			c.v[i][j] = 0;
			repf (k, 0, SIZE - 1) {
				c.v[i][j] += (a.v[i][k] * b.v[k][j]) % MOD;
				c.v[i][j] %= MOD;
			}
		}
	}
	return c;
}

Mat operator ^ (Mat a, ll k) {
	Mat c;
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
	// a
	a.v[0][0] = 9;
	a.v[1][0] = 6;
	a.v[2][0] = 4;
	a.v[3][0] = 2;
	
	// b
	b.v[0][0] = b.v[0][2] = b.v[0][3] = b.v[1][0] = b.v[2][1] = b.v[3][2] = 1;

	while (~scanf("%d%d", &l, &MOD)) {
		if (l == 0) {
			puts("0");
		} else if (l <= 4) {
			printf("%lld\n", a.v[4 - l][0] % MOD);
		} else {
			c = b ^ (l - 4);
			c = c * a;
			printf("%lld\n", c.v[0][0] % MOD);
		}
	}

	return 0;
}

