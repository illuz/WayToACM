/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-11-09 10:16:35
*  Descripton:   
*/

#define HDU
// don't forget to change I64d to I64d

#ifdef HDU
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <utility>
#include <cctype>
typedef __int64 ll;
#else	// c++11
#include <bits/stdc++.h>
typedef long long ll;
#endif

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

int t;
ll n, m, k;

int f(int a, int b, int c) {
	if (a * b * c <= 1) return 0;
	if (!(a&1)) return f(a>>1, b, c) + 1;
	if (!(b&1)) return f(a, b>>1, c) + 1;
	if (!(c&1)) return f(a, b, c>>1) + 1;
	if (a >= b && a >= c) return f((a>>1) + 1, b, c) + 1;
	if (b >= a && b >= c) return f(a, (b>>1) + 1, c) + 1;
	return f(a, b, (c>>1) + 1) + 1;
}

inline ll calc(ll x) {
	return ceil(log2(x));
}

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%I64d%I64d%I64d", &n, &m, &k);
		ll A = n * m * k;
		// if (f(A) != ceil(log2(A))) {
			// cout << n << ' ' << m  << ' ' << k;
		// }
		printf("Case #%d: %I64d %I64d\n", cas, A - 1, calc(n) + calc(m) + calc(k));

		// cout << A - 1 << ' ' << f(A) << endl;
	}
	return 0;
}

