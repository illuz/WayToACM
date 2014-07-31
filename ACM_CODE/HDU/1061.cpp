/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1061.cpp
*  Create Date: 2014-07-31 09:59:34
*  Descripton:  pow_mod 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int MOD = 10;

int t;
ll n;

// a^k % m
ll pow_mod(ll a, ll n, ll m) {
	ll ret = 1;
	a %= m;
	while (n) {
		if (n&1) {
			ret = (ret * a) % m;
		}
		a = (a * a) % m;
		n >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		printf("%lld\n", pow_mod(n, n, MOD));
	}
	return 0;
}

