/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1001.cpp
*  Create Date: 2014-10-11 19:29:04
*  Descripton:   
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

const int N = 0;

int t, n, ans;
int s[10];

bool check(int x) {
	int len = 0, y = x;
	while (y) {
		s[len] = y % 10;
		if (s[len] == 0) return false;
		len++;
		y /= 10;
	}
	if (len == 1) return true;
	repf (i, 0, len / 2)
		if (s[i] != s[len - 1 - i])
			return false;
	repf (i, 0, (len + 1) / 2 - 2)
		if (s[i] >= s[i + 1])
			return false;
	// cout << x << endl;
	return true;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		int up = (int)pow(10, (double)n);
		// cout << up << endl;
		repf (i, 1, up) {
			if (check(i)) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

