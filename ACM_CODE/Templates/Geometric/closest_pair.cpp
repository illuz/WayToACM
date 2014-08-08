/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        closest_pair.cpp
*  Create Date: 2014-08-06 09:53:01
*  Descripton:  HDU 1007
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int MAXN = 100001;

struct Point {
	double x;
	double y;
} p[MAXN];
int cnt, rec[MAXN];

bool cmpx(const Point &a, const Point &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.x);
}

bool cmpy(const int &a, const int &b) {
	return p[a].y < p[b].y || (p[a].y == p[b].y && p[a].x < p[b].x);
}

double dis(const Point &a, const Point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double minDisSolver(int l, int r) {
	if (r == l + 1)
		return dis(p[l], p[r]);
	if (r == l + 2)
		return min(dis(p[l], p[l + 1]), min(dis(p[l], p[r]), dis(p[l + 1], p[r])));

	// deal the two-side pionts
	int mid = (l + r) >> 1;
	double ans = min(minDisSolver(l, mid), minDisSolver(mid + 1, r));

	// rec the middle points
	cnt = 0;
	for (int i = l; i <= r; i++)
		if (p[i].x >= p[mid].x - ans && p[i].x <= p[mid].x + ans)
			rec[cnt++] = i;

	// deal the middle points
	sort(rec, rec + cnt, cmpy);
	for (int i = 0; i < cnt; i++)
		for (int j = i + 1; j < cnt; j++) {
			if (p[rec[j]].y - p[rec[i]].y >= ans) break;
			ans = min(ans, dis(p[rec[i]], p[rec[j]]));
		}

	return ans;
}

double minPointPairDis(int n) {
	sort(p, p + n, cmpx);
	return minDisSolver(0, n - 1);
}

int main() {
	int n;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		printf("%.2f\n", minPointPairDis(n) / 2);
	}
	return 0;
}
