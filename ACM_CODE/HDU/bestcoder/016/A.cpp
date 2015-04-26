/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-11-01 19:33:31
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

const int N = 0;
const int MOD = 1e9 + 7;

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ll ans = 0, r;
		repf (i, 1, n) {
			scanf("%I64d", &r);
			ans = (ans + (ll)i * (n - i + 1) % MOD * r % MOD) % MOD;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

