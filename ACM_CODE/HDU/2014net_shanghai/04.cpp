/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        04.cpp
*  Create Date: 2014-09-27 12:43:45
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 1100;

int t, n, m;
double p[11][N];
double dp[N][N];

int main() {
	// ios_base::sync_with_stdio(0);
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d%d", &n, &m);
		repf (i, 0, n - 1)
			repf (j, 0, m - 1) {
				scanf("%lf", &p[i][j]);
			}
		repf (i, 0, m) repf (j, 0, (1<<n)) dp[i][j] = -1.0;
		dp[0][0] = 0;
		repf (i, 0, m - 1) {
			repf (j, 0, (1<<n) - 1) {
				if (dp[i][j] < 0) continue;
				int st;
				repf (k, 0, n - 1) {
					if (!((1<<k)&j)) {
						st = j | (1<<k);
						if (st == (1<<n) - 1)
							st = 0;
						if (dp[i + 1][st] < dp[i][j] + p[k][i])
							dp[i + 1][st] = dp[i][j] + p[k][i];
					}
				}
			}
		}
		double ans = 0;
		repf (i, 0, (1<<n) - 1)
			ans = max(ans, dp[m][i]);
		printf("Case #%d: %.5lf\n", cas, ans);
	}
	return 0;
}

