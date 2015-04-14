/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-11-07 11:32:06
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 64;

ll a, b, ans;

int calclen(ll a) {
	if (a) return 1 + calclen(a >> 1);
	return 0;
}

int calc1(ll a) {
	if (a) return (a&1) + calc1(a >> 1);
	return 0;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int la = 0, lb = 0;
		cin >> a >> b;
		la = a == 0 ? 1 : calclen(a);
		lb = b == 0 ? 1 : calclen(b);
		if (la < lb)
			ans = (ll(1)<<(lb - 1)) - 1;
		else {
			ans = 0;
			for (int i = la - 1; i; i--) {
				ll x = (a>>i)&1, y = (b>>i)&1;
				if (x == y)
					ans |= (x<<i);
				else {
					ans |= (ll(1)<<i) - 1;
					break;
				}
			}
		}
		if (calc1(b) > calc1(ans)) {
			// cout << calc1(b) << calc1(ans) << endl;
			ans = b;
		}
		if (calc1(a) >= calc1(ans))
			ans = a;
		cout << ans << endl;
	}
	return 0;
}

