/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        poj2187.cpp
*  Create Date: 2013-11-23 09:34:38
*  Descripton:  rotating calipers 
*/

#include <bits/stdc++.h>
using namespace std;

#define sqr(a) ((a) * (a))

const int MAXN = 50000;
const double PI = acos(-1.0);
const int INF = 0x7fffffff;

struct Point {
	double x;
	double y;
	Point() {};
	Point(double tx, double ty) {
		x = tx;
		y = ty;
	}
	Point operator-(const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	Point operator+(const Point &b) const {
		return Point(x + b.x, y + b.y); 
	}
	Point operator*(const double &k) const {
		return Point(x * k, y * k);
	}
	double operator*(const Point &b) const {	// 点积
		return x * b.y + y * b.x;
	}
	double operator^(const Point &b) const {	// 叉积
		return x * b.y - y * b.x;
	}
	friend bool operator < (const Point &l, const Point &r) {
		return l.y < r.y || (l.y == r.y && l.x < r.x);
	}
} p[MAXN], ch[MAXN * 2];
// p, point   ch, convex hull

double dis(const Point &a, const Point &b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double ddis(const Point &a, const Point &b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

double mult(const Point &a, const Point &b, const Point &o) {
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

int Graham(Point p[], int n, Point res[]) {
	int top = 1;
	sort(p, p + n);
	if (n == 0) return 0;
	res[0] = p[0];
	if (n == 1) return 1;
	res[1] = p[1];
	if (n == 2) return 2;
	res[2] = p[2];
	for (int i = 2; i < n; i++) {
		while (top && (mult(p[i], res[top], res[top - 1]) >= 0))
			top--;
		res[++top] = p[i];
	}
	int len = top;
	res[++top] = p[n - 2];
	for (int i = n - 3; i >= 0; i--) {
		while (top != len && (mult(p[i], res[top], res[top - 1]) >= 0))
			top--;
		res[++top] = p[i];
	}
	return top;
}

double rotating_calipers(Point *p, int n) {
	n = Graham(p, n, ch);
	int q = 1;
	double ans = 0;
	ch[n] = ch[0];
	for (int p = 0; p < n; p++) {
		while (mult(ch[p + 1], ch[q + 1], ch[p]) > mult(ch[p + 1], ch[q], ch[p]))
			q = (q + 1) % n;
		ans = max(ans, max(ddis(ch[p], ch[q]), ddis(ch[p + 1], ch[q + 1])));
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		printf("%.0f\n", rotating_calipers(p, n));
	return 0;
}
