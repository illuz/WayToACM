/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        06.cpp
*  Create Date: 2014-10-06 16:19:15
*  Descripton:  greedy
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

const int N = 200010;

int x[N];
int t, n, m, l, ans;
int now, last;

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d%d%d", &n, &m, &l);
		repf (i, 1, n)
			scanf("%d", &x[i]);
		x[++n] = m;
		sort(x + 1, x + n + 1);

		now = ans = 0;
		last = l + 1;
		for (int i = 1; now < m; ) {
			if (now + l >= x[i]) {
				ans++;
				while (i <= n && now + l >= x[i])
					i++;
				last = x[i - 1] - now;
				now = x[i - 1];
			} else {
				int t = (x[i] - now) / (l + 1) - 1;
				ans += t * 2 + 1;
				now += t * (l + 1);
				last = l + 1 - last;
				now += last;
				while (i <= n && x[i] <= now)
					i++;
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

