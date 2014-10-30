/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        04_bf.cpp
*  Create Date: 2014-10-22 14:52:40
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

const int N = 5e4+10;

double x[N], xx[N], sx[N], sxx[N];
int n, k, t;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		repf (i, 1, n) {
			scanf("%lf", &x[i]);
		}
		k = n - k;
		double ans = 1e12, v;
		sort(x + 1, x + n + 1);
		repf (i, 1, n) {
			sx[i] = sx[i - 1] + x[i];
			xx[i] = x[i] * x[i];
			sxx[i] = sxx[i - 1] + xx[i];
		}
		repf (i, k, n) {
			v = (sx[i] - sx[i - k]) / k;
			double tmp = 0;
			repf (j, i - k + 1, i) {
				tmp += (x[j] - v) * (x[j] - v);
			}
			ans = min(ans, tmp);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}

