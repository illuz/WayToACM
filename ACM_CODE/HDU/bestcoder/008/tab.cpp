#include <cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<vector>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 2;
const int SIZE = 2;		// max size of the matrix

ll n, MOD;

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

ll calc() {
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)ans=(ans*2+1)%MOD;
		else ans=ans*2%MOD;
	}
	return ans;
}

int main() {
	a.v[0][0] = 4;
	a.v[0][1] = 1;
	a.v[1][1] = 1;
	b.v[0][0] = 0;
	b.v[1][0] = 1;
	//a.output();
	while (~scanf("%d%d", &n, &MOD)) {
		ll ans;
		if (n < 30) {
			ans = calc();
		} else {
			int cnt = (n + 1) / 2;
			c = a ^ cnt;
			c = c * b;
			//c.output();
			ans = c.v[0][0];
			if (n % 2 == 0) {
				ans = (ans * 2) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
