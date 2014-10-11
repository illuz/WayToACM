/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        K.cpp
*  Create Date: 2014-10-11 10:55:22
*  Descripton:  gcd 
*/

#define HDU
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

const int N = 1010;

int n, x[N], y[N], z[N];
bool flag;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

bool check(int i, int j) {
	int t = gcd(x[i], x[j]), a = y[j] - z[i], b = z[j] - y[i];
	if (a % t == 0 || b % t == 0)
		return true;
	if (a < 0 && b > 0)
		return true;
	if (b / t - a / t > 0)
		return true;
	return false;
}

int main() {
	while (~scanf("%d", &n)) {
		repf (i, 0, n - 1)
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
		flag = true;
		repf (i, 0, n - 1) repf (j, i + 1, n - 1)
			if (check(i, j)) {
				flag = false;
				break;
			}
		if (flag)
			puts("Can Take off");
		else
			puts("Cannot Take off");
	}
	return 0;
}

