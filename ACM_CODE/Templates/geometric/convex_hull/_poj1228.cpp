/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        _poj1228.cpp
*  Create Date: 2013-11-17 17:03:41
*  Descripton:  angle sort 
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define sqr(a) ((a) * (a))
#define dis(a, b) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y))

const int MAXN = 1010;
const double PI = acos(-1.0);
int maxp;
bool flag;

struct Point {
	int x;
	int y;
	Point(double a = 0, double b = 0) : x(a), y(b) {}
} p[MAXN], ch[MAXN * 2], o;
// p, point   ch, convex hull

bool mult(Point a, Point b, Point o) {
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

bool cmp(const Point &a, const Point &b) {
//	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
	return atan2(a.y, a.x) < atan2(b.y, b.x);
}

bool judge(Point tt[], int n) {
	for (int i = 2; i < n; i++) {
		if (!flag && mult(tt[i - 2], tt[i - 1], tt[i]))
			flag = true;
		if (!mult(tt[i - 2], tt[i - 1], tt[i]) == 0 && !mult(tt[i - 1], tt[i], tt[(i + 1) % n]) == 0 && !mult(tt[i], tt[(i + 1) % n], tt[(i + 2) % n]) == 0)
			return false;
	}
	return true;
}

int n, t;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		maxp = 0;
		flag = false;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
			if (p[maxp].y > p[i].y || (p[maxp].y == p[i].y && p[maxp].x > p[i].x))
				maxp = i;
		}
		o = p[maxp];

		sort (p, p + n, cmp);
		if (n >= 6 && judge(p, n) && flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

