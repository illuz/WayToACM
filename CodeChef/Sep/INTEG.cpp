 /*
 *   Author:        illuz <iilluzen[at]gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          INTEG.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-09-06 18:13:53
 *   Descripton:    trick 
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

const int MAXN = 100001; 
int a[MAXN];
LL sum[MAXN];
int n, x;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &n);
	repf(i, 1, n) 
		scanf("%d", &a[i]);
	scanf("%d", &x);
	sort(a + 1, a + n + 1);
	repf(i, 1, n)
		sum[i] = sum[i - 1] + (a[i] < 0 ? -a[i] : 0);
	if (x >= n || a[x + 1] >= 0)
		printf("%lld\n", sum[n]);
	else
		printf("%lld\n", sum[x]);
	return 0;
}

