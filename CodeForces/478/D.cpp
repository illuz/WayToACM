/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-10-17 10:15:48
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

ll dp[N];
ll r, g;

int main() {
	cin >> r >> g;
	dp[0] = 1;
	for (int h = 1; ; h++) {
		ll tot = h * (h + 1) / 2;
		if (tot > r + g)
			break;
		for (ll i = r; i >= 0; i--) {
			if (i >= h)
				dp[i] = (dp[i] + dp[i - h]) % MOD;
			if (tot - i > g)
				dp[i] = 0;
		}
	}
	ll ans = 0;
	for (ll x : dp)
		ans = (ans + x) % MOD;
	cout << ans << endl;
	return 0;
}

