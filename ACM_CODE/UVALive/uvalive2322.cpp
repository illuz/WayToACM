 /*
 *   Author:        illuz <iilluzen[at]gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          uvalive2322.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-09-06 20:50:20
 *   Descripton:    greedy, sort 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mc(a) memset(a, 0, sizeof(a))

const int MAXN = 5001;
struct P {
	int lhs, rhs;
} p[MAXN];
int t, n;
bool vis[MAXN];

bool cmp(P a, P b) {
	if (a.lhs != b.lhs) return a.lhs < b.lhs;
	else return a.rhs < b.rhs;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		// input
		scanf("%d", &n);
		rep(i, n) scanf("%d%d", &p[i].lhs, &p[i].rhs);
		// sort
		sort(p, p + n, cmp);
		// solve
		mc(vis);
		int cnt = 0;
		while (1) {
			int i;
			for (i = 0; i < n; i++)
				if (!vis[i]) break;
			if (i == n) break;
			vis[i] = true;
			int l = p[i].lhs, r = p[i].rhs;
			for (i++; i < n; i++)
				if (!vis[i] && p[i].lhs >= l && p[i].rhs >= r) {
					vis[i]++;
					l = p[i].lhs;
					r = p[i].rhs;
				}
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

