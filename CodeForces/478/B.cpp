/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-10-17 09:07:14
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

ll n, m;

inline ll calc(ll x) {
	return x * (x - 1) / 2;
}

int main() {
	cin >> n >> m;
	if (m == 1) {
		ll ans = calc(n);
		cout << ans << ' ' << ans << endl;
	} else if (n == m) {
		cout << "0 0" << endl;
	} else {
		ll kmax = calc(n - m + 1);
		ll res = n % m;
		ll kmin = calc(n / m) * (m - res) + calc(n / m + 1) * res;
		cout << kmin << ' ' << kmax << endl;
	}
	return 0;
}

