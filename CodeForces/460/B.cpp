/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-08-20 23:49:52
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

ll calc(ll n) {
	if (n <= 0 || n >= 1e9) return -1;
	ll ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

ll pp(int a, ll b) {
	ll ret = 1;
	while (b--) {
		ret *= a;
	}
	return ret;
}

int main() {
	ll a, b, c;
	while (cin >> a >> b >> c) {
		vector<ll> ans;
		repf (i, 0, 100) {
			ll x = b * pp(i, a) + c;
			if (calc(x) == i) {
				ans.push_back(x);
			}
		}
		cout << ans.size() << endl;
		if (ans.size()) {
			//		sort(ans.begin(), ans.end());
			rep (i, ans.size() - 1) {
				cout << ans[i] << ' ';
			}
			cout << ans[ans.size() - 1];
			cout << endl;
		}
	}
	return 0;
}

