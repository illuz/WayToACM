/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1154.cpp
*  Create Date: 2014-07-31 08:46:56
*  Descripton:  aoj 1154
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 30;

ll n;
ll dp[N];

// table
void init() {
	repf (i, 1, N - 1) {
		ll ans = 0, t = (1<<i), v = 1;
		while (t) {
			ans += (t>>1) * v;	// there was (t>>1) numbers whose last 1 is in log2(v)
			v <<= 1;
			t >>= 1;
		}
		dp[i] = ans;
//		cout << ans << ' ';
	}
}

ll solve(ll n) {
	int i = 0;
	ll ret = 0;
	while (n) {
		if (n & 1)
			ret += dp[i] + (1<<i);		// don't forget there must be a 1<<i
		n >>= 1;
		i++;
	}
	return ret;
}

// brute force
ll bf(ll n) {
	ll ans = 0;
	repf (i, 1, n)
		ans += i&(-i);
	return ans;
}

int main() {

	init();

	while (cin >> n) {
		cout << solve(n) << endl;
//		cout << n << ' ' << solve(n) << ' ' << bf(n) << endl;
	}
	return 0;
}

