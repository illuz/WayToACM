/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva607.cpp
*  Create Date: 2013-11-17 19:30:55
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>

#define min(a, b) ((a) < (b) ? (a) : (b))

const int INF = 0x7fffffff;
const int MAXN = 1010;

int n, l, c, t[MAXN];
int num[MAXN], dp[MAXN], sum[MAXN];

int getDI(int x) {
	if (x == 0) return 0;
	else if (x >= 1 && x <= 10) return -c;
	else return (x - 10) * (x - 10);
}

int main() {
	int cas = 0;
	while (~scanf("%d", &n) && n) {
		scanf("%d%d", &l, &c);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &t[i]);
			sum[i] = sum[i - 1] + t[i];
		}

		for (int i = 1; i <= n; i++) {
			num[i] = dp[i] = INF;
			for (int j = 1; j <= i; j++) {
				if (sum[i] - sum[j - 1] <= l) {
					int d = getDI(l - (sum[i] - sum[j - 1]));

					if (num[j - 1] + 1 < num[i]) {
						num[i] = num[j - 1] + 1;
						dp[i] = dp[j - 1] + d;
					} else if (num[j - 1] + 1 == num[i])
						dp[i] = min(dp[i], dp[j - 1] + d);
				}
			}
		}
		if (cas) puts("");
		printf("Case %d:\n", ++cas);
		printf("Minimum number of lectures: %d\n", num[n]);
		printf("Total dissatisfaction index: %d\n", dp[n]);
	}
	return 0;
}

