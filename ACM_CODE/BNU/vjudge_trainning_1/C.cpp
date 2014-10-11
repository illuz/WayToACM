/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-10-11 10:06:54
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

const int N = 65;

ll a, b;
int flag;
int num[N];

// calculate the 1 of every pos 0~x
void calc(ll x) {
	ll t = 1;
	repf (i, 0, 63) {
		if (t > x)
			return;
		t <<= 1;
		num[i] += flag * (x - x % t) / 2;
		if (x % t > t / 2)
			num[i] += flag * (x % t - t / 2);
	}
}

int main() {
	while (~scanf("%I64d%I64d", &a, &b)) {
		memset(num, 0, sizeof(num));
		flag = 1;
		calc(b + 1);
		flag = -1;
		calc(a);
		ll ans = 0;
		repf (i, 0, 63) {
			ans += num[i] / 2;
			num[i + 1] += num[i] / 2;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

