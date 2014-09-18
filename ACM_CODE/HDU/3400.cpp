/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3400.cpp
*  Create Date: 2014-09-18 09:44:01
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

const double EPS = 1e-8;

struct Point {
	double x;
	double y;
} a, b, c, d, e, f;

int t;
double p, q, r;

double dis(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double calc(double alpha) {
	f.x = c.x + (d.x - c.x) * alpha;
	f.y = c.y + (d.y - c.y) * alpha;
	return dis(f, d) / q + dis(e, f) / r;
}

double inter_tri(double alpha) {
	e.x = a.x + (b.x - a.x) * alpha;
	e.y = a.y + (b.y - a.y) * alpha;

	double l = 0.0, r = 1.0, mid, mmid, cost;
	while (r - l > EPS) {
		mid = (l + r) / 2;
		mmid = (mid + r) / 2;
		cost = calc(mid);
		if (cost <= calc(mmid))
			r = mmid;
		else
			l = mid;
	}
	return dis(a, e) / p + cost;
}

double solve() {
	double l = 0.0, r = 1.0, mid, mmid, ret;
	while (r - l > EPS) {
		mid = (l + r) / 2;
		mmid = (mid + r) / 2;
		ret = inter_tri(mid);
		if (ret <= inter_tri(mmid))
			r = mmid;
		else
			l = mid;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> a.x >> a.y >> b.x >> b.y;
		cin >> c.x >> c.y >> d.x >> d.y;
		cin >> p >> q >> r;
		printf("%.2f\n", solve());
	}
	return 0;
}

