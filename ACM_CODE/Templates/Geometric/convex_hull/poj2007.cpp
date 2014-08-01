/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        poj2007.cpp
*  Create Date: 2013-11-14 18:55:37
*  Descripton:  convex hull 
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define sqr(a) ((a) * (a))
#define dis(a, b) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y))

const int MAXN = 110;
const double PI = acos(-1.0);

struct Point {
	int x;
	int y;
	Point(double a = 0, double b = 0) : x(a), y(b) {}
	friend bool operator < (const Point &l, const Point &r) {
		return l.y < r.y || (l.y == r.y && l.x < r.x);
	}
} p[MAXN], ch[MAXN];
// p, point   ch, convex hull

double mult(Point a, Point b, Point o) {
	return (a.x - o.x) * (b.y - o.y) >= (b.x - o.x) * (a.y - o.y);
}

int Graham(Point p[], int n, Point res[]) {
	int top = 1;
	sort(p, p + n);
	if (n == 0) return 0;
	res[0] = p[0];
	if (n == 1) return 0;
	res[1] = p[1];
	if (n == 2) return 0;
	res[2] = p[2];
	for (int i = 2; i < n; i++) {
		while (top && (mult(p[i], res[top], res[top - 1])))
			top--;
		res[++top] = p[i];
	}
	int len = top;
	res[++top] = p[n - 2];
	for (int i = n - 3; i >= 0; i--) {
		while (top != len && (mult(p[i], res[top], res[top - 1])))
			top--;
		res[++top] = p[i];
	}
	return top;
}

int n;

int main() {
	while (scanf("%d%d", &p[n].x, &p[n].y) != EOF)
		n++;
	n = Graham(p, n, ch);
	int t;
	for (int i = 0; i < n; i++)
		if (ch[i].x == 0 && ch[i].y == 0) {
			t = i;
			break;
		}

	for (int i = t; i < n; i++)
		printf("(%d,%d)\n", ch[i].x, ch[i].y);
	for (int i = 0; i < t; i++)
		printf("(%d,%d)\n", ch[i].x, ch[i].y);
	return 0;
}
