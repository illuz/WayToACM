/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-11-09 10:16:35
*  Descripton:   
*/

// #define HDU
// don't forget to change lld to I64d

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

int f(ll x) {
	if (x <= 1) return 0;
	if (x % 2) return max(f(x/2), f(x/2+1)) + 1;
	else return f(x/2) + 1;
}

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%lld%lld%lld", &n, &m, &k);
		ll A = n * m * k;
		// if (f(A) != ceil(log2(A))) {
			// cout << n << ' ' << m  << ' ' << k;
		// }
		printf("Case #%d: %lld %d\n", cas, A - 1, f(A));

		// cout << A - 1 << ' ' << f(A) << endl;
	}
	return 0;
}

