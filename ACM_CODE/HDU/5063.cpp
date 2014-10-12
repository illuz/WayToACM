/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        5063.cpp
*  Create Date: 2014-10-12 08:48:15
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

const int N = 1e5 + 10;
const int MOD = 1000000007;

int t, n, m, o[N], cnt;
char op[3];

ll pow_mod(ll a, ll n, ll m) {
	ll ret = 1;
	while (n) {
		if (n&1) ret = (ret * a) % m;
		a = (a * a) % m;
		n >>= 1;
	}
	return ret;
}

void solve(int n, int pos, int cur) {
	ll p = 1;
	for (int i = cur - 1; i >= 0; i--) {
		if (o[i] == 1) {
			if (pos > (n + 1) / 2)
				pos = 2 * (pos - (n + 1) / 2);
			else
				pos = 2 * pos - 1;
		} else if (o[i] == 2) {
			pos = n + 1 - pos;
		} else {
			p = (p * 2) % (MOD - 1);
		}
	}
	printf("%d\n", (int)pow_mod(pos, p, MOD));
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		cnt = 0;
		repf (i, 1, m) {
			scanf("%s%d", op, &o[cnt++]);
			if (op[0] == 'Q') {
				cnt--;
				solve(n, o[cnt], cnt);
			}
		}
	}
	return 0;
}

