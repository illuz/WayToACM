 /*
 *   Author:        illuz <iilluzen@gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          D.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-08-19 00:44:32
 *   Descripton:    codechef 13.8 D Geometry
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
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
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;

/****** TEMPLATE ENDS ******/

const int MAXN = 100;

int main() {
	int n, cnt = 0;
	int x1, y1, x2, y2, x3, y3;
	int e1, e2, e3;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		e1 = sqr(x1 - x2) + sqr(y1 - y2);
		e2 = sqr(x1 - x3) + sqr(y1 - y3);
		e3 = sqr(x3 - x2) + sqr(y3 - y2);
//		cout << e1 << ' ' << e2 << ' '<< e3 << endl;
		if (e1 + e2 == e3 || e2 + e3 == e1 || e1 + e3 == e2)
			cnt++;
//		cout << cnt << endl;
	}
	printf("%d\n", cnt);
	return 0;
}

