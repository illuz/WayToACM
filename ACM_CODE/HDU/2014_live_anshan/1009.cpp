/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1009.cpp
*  Create Date: 2014-10-22 13:16:41
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

const int N = 1010;
struct Point {
	int x, y;
	int t;
} p[N];
int n, t;

bool cmp(Point a, Point b) {
	return a.t < b.t;
}

inline double dis(double a, double b, double c, double d) {
	return sqrt((a - b) * (a - b) + (c - d) * (c - d));
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		repf (i, 0, n - 1) {
			cin >> p[i].t >> p[i].x >> p[i].y;
		}
		sort(p, p + n, cmp);
		double ans = 0.0;
		repf (i, 1, n - 1) {
			ans = max(ans, dis(p[i].x, p[i - 1].x, p[i].y, p[i - 1].y) / (p[i].t - p[i - 1].t));
		}
		printf("%.10f\n", ans);
	}
	return 0;
}

