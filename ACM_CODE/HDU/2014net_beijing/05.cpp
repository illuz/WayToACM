/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        05.cpp
*  Create Date: 2014-10-06 10:35:39
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

const int N = 1010;

int t, n, k, v;
double ans;
bitset<N> p[N];

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		ans = 0.0;
		scanf("%d", &n);
		repf (i, 0, n - 1) {
			p[i].reset();
			p[i][i] = true;
			scanf("%d", &k);
			while (k--) {
				scanf("%d", &v);
				p[i][v - 1] = true;
			}
		}
		repf (j, 0, n - 1) {
			repf (i, 0, n - 1) {
				if (p[i][j])
					p[i] |= p[j];
			}
		}

		repf (i, 0, n - 1) {
			int cnt = 0;
			repf (j, 0, n - 1)
				if (p[j][i])
					cnt++;
			ans += 1.0 / cnt;
		}
		printf("Case #%d: %.5f\n", cas, ans);
	}
	return 0;
}

