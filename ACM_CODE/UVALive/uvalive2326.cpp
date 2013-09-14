 /*
 *   Author:        illuz <iilluzen[at]gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          uvalive2326.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-09-07 14:19:24
 *   Descripton:    UVALive 2326 Moving Tables, greedy 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mc(a) memset(a, 0, sizeof(a))

const int MAXN = 210;
struct P {
	int lhs, rhs;
} p[MAXN];
int t, n, vis[MAXN], rec[MAXN], a, b;

bool cmp(P a, P b) {
	return a.lhs < b.lhs;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 0) {
			printf("0\n");
			continue;
		}
		rep(i, n) {
		   	scanf("%d%d", &a, &b);
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			if (a == b) i--, n--;
			else {
				p[i].lhs = min(a, b);
				p[i].rhs = max(a, b);
			}
		}
		sort(p, p + n, cmp);
		int ans = 0;
		mc(vis); mc(rec);
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0) {
				vis[i]++;
				int ok = false;
				for (int j = 1; j <= ans && !ok; j++)
					if (rec[j] < p[i].lhs)
						rec[j] = p[i].rhs, ok = true;
				if (!ok)
					rec[++ans] = p[i].rhs;
			}
		}
		if (ans == 0) printf("10\n");
		else printf("%d\n", ans * 10);
	}
	return 0; 
}
