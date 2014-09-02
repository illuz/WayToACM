/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        LA5059.cpp
*  Create Date: 2014-09-01 19:56:11
*  Descripton:  Nim
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

ll SG(ll x) {
	return x&1 ? SG(x / 2) : x / 2;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		ll a, v = 0;
		scanf("%d", &n);
		repf (i, 0, n - 1) {
			scanf("%lld", &a);
			v ^= SG(a);
		}
		if (v)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

