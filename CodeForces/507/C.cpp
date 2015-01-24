/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2015-01-24 00:33:03
*  Descripton:  Binary tree. Find out the rule.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, ans;

void solve(ll n, ll k, ll ck) {
	if (!n || k <= 1)
		return;

	if (((k >> (n - 1))&1) == ck) {	// add half
		ans += (((ll)1) << n);
		solve(n - 1, k, ck);
	} else {						// add 1
		ans++;
		solve(n - 1, k, !ck);
	}
}

int main() {
	while (cin >> n >> k) {
		ans = 0;
		// cout << (1<<n) + k - 1 << endl;
		solve(n, (1LL<<n) + k - 1, 1);
		cout << ans << endl;
	}
	return 0;
}

