/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2546.cpp
*  Create Date: 2014-08-12 10:49:53
*  Descripton:  Geo 
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;
const double PI = acos(-1.0);

struct Round {
	double x, y;
	double r;
} r[2];

double dis(Round a, Round b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double insection_of_rounds(Round a, Round b) {
	double d = dis(a, b);
	if (d >= a.r + b.r)
		return 0;
	if (d <= fabs(a.r - b.r)) {
		double r = a.r < b.r ? a.r : b.r;
		return PI * r * r;
	}
	double ang1 = acos((a.r * a.r + d * d - b.r * b.r) / 2. / a.r / d);
	double ang2 = acos((b.r * b.r + d * d - a.r * a.r) / 2. / b.r / d);
	double ret = ang1 * a.r * a.r + ang2 * b.r * b.r - d * a.r * sin(ang1);
	return ret;
}

int main() {
	while (~scanf("%lf%lf%lf%lf%lf%lf", &r[0].x, &r[0].y, &r[0].r, &r[1].x, &r[1].y, &r[1].r)) {
		printf("%.3f\n", insection_of_rounds(r[0], r[1]));
	}
	return 0;
}

