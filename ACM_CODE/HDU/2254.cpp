/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2254.cpp
*  Create Date: 2014-08-04 10:52:29
*  Descripton:  matrix
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
const int SIZE = 32;		// max size of the matrix
const int MOD = 2008;

int n, k, p1, p2;
ll v1, v2, t1, t2;
map<int, int> mp;

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

Mat calc(Mat a, int n) {
	if (n == 1)
		return a;
	if (n&1)
		return (a^n) + calc(a, n - 1);
	else
		return calc(a, n/2) * ((a^(n/2)) + 1);
}

int main() {
	while (~scanf("%d", &n)) {
		a.init();
		mp.clear();
		int cnt = 0;
		while (n--) {
			scanf("%d%d", &p1, &p2);
			if (mp.find(p1) == mp.end())
				p1 = mp[p1] = cnt++;
			else
				p1 = mp[p1];
			if (mp.find(p2) == mp.end())
				p2 = mp[p2] = cnt++;
			else
				p2 = mp[p2];
			a.v[p1][p2]++;
		}
		a.n = cnt;

		scanf("%d", &k);
		while (k--) {
			scanf("%lld%lld%lld%lld", &v1, &v2, &t1, &t2);
			if (mp.find(v1) == mp.end() || mp.find(v2) == mp.end()) {
				puts("0");
				continue;
			}
			v1 = mp[v1];
			v2 = mp[v2];
			if (t1 > t2)
				swap(t1, t2);
			if (t1 == 0) {
				if (t2 == 0)
					puts("0");
				else
					printf("%lld\n", calc(a, t2).v[v1][v2]);
			}
			else if (t1 == 1)
				printf("%lld\n", calc(a, t2).v[v1][v2]);
			else {
				printf("%lld\n", ((calc(a, t2).v[v1][v2] - calc(a, t1 - 1).v[v1][v2]) + MOD) % MOD);
			}
		}
	}
	return 0;
}

