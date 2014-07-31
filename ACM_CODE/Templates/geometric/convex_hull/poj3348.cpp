/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        poj3348.cpp
*  Create Date: 2013-11-17 23:27:28
*  Descripton:  convex hull + triangle area
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define sqr(a) ((a) * (a))
#define dis(a, b) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y))

const int MAXN = 10010;

struct Point {
	int x;
	int y;
	Point(double a = 0, double b = 0) : x(a), y(b) {}
	friend bool operator < (const Point &l, const Point &r) {
		return l.y < r.y || (l.y == r.y && l.x < r.x);
	}
} p[MAXN], ch[MAXN << 1], o(0, 0);
// p, point   ch, convex hull

double mult(const Point &a, const Point &b, const Point &o) {
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

double Graham(Point p[], int n, Point res[]) {
	int top = 1;
	sort(p, p + n);
	if (n == 0) return 0;
	res[0] = p[0];
	if (n == 1) return 0;
	res[1] = p[1];
	if (n == 2) return 0;
	res[2] = p[2];
	//res[2] = p[2];
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
	// clac the c
	/*
	double c = dis(res[0], res[top - 1]);
	for (int i = 0; i < top - 1; i++)
		c += dis(res[i], res[i + 1]);
	return c;
	*/
	// calc the area
	double s = 0;
	res[top] = res[0];
	for (int i = 0; i < top; i++)
		s += mult(res[i], res[i + 1], o);
	return fabs(s) / 2;
}

int n;
int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		printf("%d\n", (int)(Graham(p, n, ch) / 50));
	}
	return 0;
}

