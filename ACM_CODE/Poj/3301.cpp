/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3301.cpp
*  Create Date: 2014-09-18 09:25:04
*  Descripton:  triple
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 31;
const double PI = acos(-1.0);
const double EPS = 1e-12;

int t, n;
double x[N], y[N];

inline double calc(double a) {
	double minx = 1000, miny = 1000, maxx = -1000, maxy = -1000;
	double xx, yy;
	repf (i, 1, n) {
		xx = x[i] * cos(a) - y[i] * sin(a);
		yy = x[i] * sin(a) + y[i] * cos(a);
		minx = min(minx, xx);
		maxx = max(maxx, xx);
		miny = min(miny, yy);
		maxy = max(maxy, yy);
	}
	return max(maxx - minx, maxy - miny);
}

int main() {
	ios_base::sync_with_stdio(0);

	double l, r, mid, mmid, ans;
	cin >> t;
	while (t--) {
		cin >> n;
		repf (i, 1, n) {
			cin >> x[i] >> y[i];
		}
		l = 0.0;
		r = PI;
		while (r - l > EPS) {
			mid = (l + r) / 2;
			mmid = (mid + r) / 2;
			ans = calc(mid);
			if (ans <= calc(mmid))
				r = mmid;
			else
				l = mid;
		}
		printf("%.2f\n", ans * ans);
		// brute force
//		ans = 1000;
//		for (double i = 0.0; i <= PI; i += 0.00005)
//			ans = min(ans, calc(i));
//		printf("%.2lf\n", ans * ans);
	}
	return 0;
}

