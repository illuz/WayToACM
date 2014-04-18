 /*
 *   Author:        illuz <iilluzen[at]gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          uva714.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-09-04 12:01:49
 *   Descripton:    UVA 714 Copying Books, greedy 
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
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;

/****** TEMPLATE ENDS ******/

const int MAXN = 501;
int t, k, m;
LL a[MAXN], n[MAXN], p[MAXN][MAXN], Min, Max, mid, ans;

void output() {
	int tk = k - 1;
	repd(i, m - 1, 0) {
		if (ans + a[i] > Max || i == k - 1) {
			k--;
			ans = 0;
		}
		ans += a[i];
		p[tk][n[tk]++] = a[i];
	}
	rep(i, k) {
		repd(j, n[i] - 1, 0) {
			if (i != 0 || j != n[i] - 1) printf(" ");
			printf("%lld", p[i][j]);
		}
		if (i != k - 1) printf(" /");
	}
	printf("\n");
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &k, &m);
		rep(i, m) {
			scanf("%lld", &a[i]);
			if (a[i] > Min) Min = a[i];
			Max += a[i];
		}
		Min--;
		while (1) {
			mid = (Max = Min) / 2;
			if (mid == Min) break;
			int tk = ans = 0;
			int i;
			for (i = 0; i < m; i++) {
				if (ans + a[i] > mid) {
					tk++;
					if (tk == k) break;
					ans = 0;
				}
				ans += a[i];
			}
			if (i == m) Max = mid;
			else Min = mid;
		}
		ans = 0;
		mc(n);
		output();
	}
	return 0;
}

