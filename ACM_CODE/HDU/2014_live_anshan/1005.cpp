/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1005.cpp
*  Create Date: 2014-10-22 13:28:48
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

const int N = 110;

int t, n, m;
int g[N][N], s[N];
ll d[N][N];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(d, 0, sizeof(d));
		scanf("%d%d", &m, &n);
		repf (i, 1, n) repf (j, 1, n) {
			scanf("%d", &g[i][j]);
		}
		repf (i, 1, n)
			d[1][i] = 0;
		repf (i, 1, m) {
			scanf("%d", &s[i]);
		}
		repf (i, 2, m) {
			if (s[i] == -1) {
				if (s[i - 1] == -1) {
					repf (j, 1, n) repf (k, 1, n) {
						d[i][j] = max(d[i][j], d[i - 1][k] + g[k][j]);
					}
				} else {
					repf (k, 1, n)
						d[i][k] = max(d[i][k], d[i - 1][s[i - 1]] + g[s[i - 1]][k]);
				}
			} else {
				if (s[i - 1] == -1) {
					repf (k, 1, n) {
						d[i][s[i]] = max(d[i][s[i]], d[i - 1][k] + g[k][s[i]]);
					}
				} else {
					d[i][s[i]] = d[i - 1][s[i - 1]] + g[s[i - 1]][s[i]];
				}
			}
		}
		ll ans = 0;
		repf (i, 1, n)
			ans = max(ans, d[m][i]);
		printf("%I64d\n", ans);
	}
	return 0;
}

