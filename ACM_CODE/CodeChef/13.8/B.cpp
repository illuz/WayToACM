 /*
 *   Author:        illuz <iilluzen@gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          B.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-08-19 01:02:47
 *   Descripton:    CC 13.8 B 
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

const int MAXN = 100100;
int num[MAXN];

int main() {
	int r, l, k;
	int n, q, cnt;
	scanf("%d%d", &n, &q);
	rep(i, n) scanf("%d", &num[i + 1]);
	while (q--) {
		scanf("%d%d%d", &l, &r, &k);
		cnt = 0;
		repf(i, l, r)
			if (num[i] % k == 0)
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}

