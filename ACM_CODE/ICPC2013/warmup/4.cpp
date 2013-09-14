/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        4.cpp
*  Create Date: 2013-09-08 15:18:39
*  Descripton:  jihe 
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repu(i, a, b) for (int i = (a); i < (b); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;

/****** TEMPLATE ENDS ******/

#define X first
#define Y second

const int MAXN = 110;
int t, n;
pair<double, double> a[MAXN];
double sum;

int main() {
	scanf("%d", &t);
	while (t--) {
		double Min = 0xfffffff;
		scanf("%d", &n);
		rep(i, n) scanf("%lf%lf", &a[i].X, &a[i].Y);
		rep(i, n) repu(j, i, n) repu(k, j, n) {
			sum = a[i].X * a[j].Y + a[j].X * a[k].Y + a[k].X * a[i].Y;
			sum -= a[i].Y * a[j].X + a[j].Y * a[k].X + a[k].Y * a[i].X;
			sum /= 2;
			if (sum <= 1e-9) continue;
			if (sum < Min)
				Min = sum;
		}
		if (Min != 0xfffffff)
			printf("%.2lf\n", Min);
		else printf("Impossible\n");
	}
	return 0;
}
