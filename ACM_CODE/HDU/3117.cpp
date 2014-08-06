/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3117.cpp
*  Create Date: 2014-08-04 10:25:26
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 41;
const int SIZE = 2;		// max size of the matrix
const int MOD = 10000;

ll n;
ll tab[N];
double ans;

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

double fib(int x) {
	return -0.5 * log(5.0) / log(10.0) + ( (double)n) * log((sqrt(5.0) + 1) / 2) / log(10.0);
}

void table() {
	// table
	tab[0] = 0;
	tab[1] = 1;
	repf (i, 2, 40)
		tab[i] = tab[i - 1] + tab[i - 2];
}

void pre4(int n) {
	ans = fib(n);
	ans -= floor(ans);
	ans = pow(10.0, ans);
	while (ans < 1000)
		ans *= 10;
	printf("%d", (int)ans);
}

void last4(int n) { 
	a.init(0);
	a.v[0][0] = a.v[0][1] = a.v[1][0] = 1;

	b = a ^ (n - 1);
	printf("%04lld\n", b.v[0][0]);
}

int main() {
	table();
	while (~scanf("%lld", &n)) {
		if (n < 40) {
			printf("%lld\n", tab[n]);
			continue;
		}
		pre4(n);
		printf("...");
		last4(n);
	}
	return 0;
}
