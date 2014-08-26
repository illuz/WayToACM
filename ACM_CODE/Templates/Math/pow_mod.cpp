/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        pow_mod.cpp
*  Create Date: 2014-07-31 11:16:21
*  Descripton:  abmod, pow_mod, super_mod 
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 0;

// a * b mod m
ll abmod(ll a, ll b, ll m) {
	a %= m;
	b %= m;
	ll s = 0;
	while (b) {
		if (b&1)
			s = (s + a) % m;
		b >>= 1;
		a = (a<<1) % m;
	}
	return s;
}

// a^b mod m
// super power mod -> logn*logn
ll pow_mod(ll a, ll n, ll m) {
	ll ret = 1;
	while (n) {
		if (n&1)
			ret = abmod(ret, a, m);
		a = abmod(a, a, m);
//			ret = (ret * a) % m;
//		a = (a * a) % m;
		n >>= 1;
	}
	return ret;
}

int main() {
	ll n;
	while (cin >> n) {
		cout << pow_mod(n, n + 1, 1000) << endl;
	}
	return 0;
}

