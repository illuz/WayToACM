/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        poj1873.cpp
*  Create Date: 2013-11-14 19:29:19
*  Descripton:  convex hull 
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define sqr(a) ((a) * (a))
#define dis(a, b) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y))

const int MAXN = 20;
const double PI = acos(-1.0);
const int INF = 0x7fffffff;

struct Point {
	double x;
	double y;
	int v;
	int l;
	Point(double a = 0, double b = 0) : x(a), y(b) {}
	friend bool operator < (const Point &l, const Point &r) {
		return l.y < r.y || (l.y == r.y && l.x < r.x);
	}
} p[MAXN], ch[MAXN * 2], tmp[MAXN];
// p, point   ch, convex hull

double mult(Point a, Point b, Point o) {
	return (a.x - o.x) * (b.y - o.y) >= (b.x - o.x) * (a.y - o.y);
}

double Graham(Point p[], int n, Point res[]) {
	int top = 1;
	sort(p, p + n);
	if (n == 0) return 0;
	res[0] = p[0];
	if (n == 1) return 0;
	res[1] = p[1];
	if (n == 2) return dis(p[0], p[1]) * 2;
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
	// c
	double c = dis(res[0], res[top - 1]);
	for (int i = 0; i < top - 1; i++)
		c += dis(res[i], res[i + 1]);
	return c;
}

int n, cas = 0;

int main() {
	while (scanf("%d", &n) && n) {

		for (int i = 0; i < n; i++)
			scanf("%lf%lf%d%d", &p[i].x, &p[i].y, &p[i].v, &p[i].l);

		int min_cut = INF, min_val = INF, ans = 0;
		double res_len = 0;

		for (int bit = 0; bit < (1 << n); bit++) {
			int res = 0, cut_val = 0;
			double cut_len = 0;

			for (int i = 0; i < n; i++)
				if (bit & (1 << i)) {
					cut_len += p[i].l;
					cut_val += p[i].v;
				}
				else {
					tmp[res].x = p[i].x;
					tmp[res++].y = p[i].y;
				}

			if (cut_val > min_val) continue;
			double c = Graham(tmp, res, ch);
			if (cut_len >= c) 
				if (cut_val < min_val || (cut_val == min_val && n - res < min_cut)) {
					ans = bit;
					min_val = cut_val;
					min_cut = n - res;
					res_len = cut_len - c;
				}
		}	
		if (cas) puts("");
		printf("Forest %d\n", ++cas);
		printf("Cut these trees:");
		for (int i = 0; i < n; i++)
			if (ans & (1 << i))
				printf(" %d", i + 1);
		printf("\nExtra wood: %.2f\n", res_len);
	}
	return 0;
}
