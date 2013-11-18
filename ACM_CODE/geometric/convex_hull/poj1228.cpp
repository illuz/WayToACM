/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        poj1228.cpp
*  Create Date: 2013-11-15 04:24:51
*  Descripton:  convex hull 
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

struct Point {
	int x;
	int y;
	Point(double a = 0, double b = 0) : x(a), y(b) {}
	friend bool operator < (const Point &l, const Point &r) {
		return l.y < r.y || (l.y == r.y && l.x < r.x);
	}
} p[MAXN], ch[MAXN * 2];
// p, point   ch, convex hull

bool mult(Point a, Point b, Point o) {
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

bool Graham(Point p[], int n, Point res[]) {
	int top = 1;
	sort(p, p + n);
	res[0] = p[0];
	res[1] = p[1];
	res[2] = p[2];
	for (int i = 2; i < n; i++) {
		while (top && (mult(p[i], res[top], res[top - 1]) < 0))
			top--;
		res[++top] = p[i];
	}
	int len = top;
	res[++top] = p[n - 2];
	for (int i = n - 3; i >= 0; i--) {
		while (top != len && (mult(p[i], res[top], res[top - 1]) < 0))
			top--;
		res[++top] = p[i];
	}
	for (int i = 2; i < top; i++)
		if (mult(res[i - 2], res[i - 1], res[i]) == 0 || mult(res[i - 1], res[i], res[(i + 1) % top]) == 0 || mult(res[i], res[(i + 1) % top], res[(i + 2) % top]) == 0)
			return false;
	return true;
}

int n, t;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		if (n >= 6 && Graham(p, n, ch))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

