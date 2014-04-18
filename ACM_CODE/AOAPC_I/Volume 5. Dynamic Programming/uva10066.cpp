/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10066.cpp
*  Create Date: 2013-09-21 09:31:21
*  Descripton:  dp, LCS 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;
int n, m, dp[2][MAXN], a[MAXN], b[MAXN];

int main() {
	int cas = 0, k = 1;
	while (scanf("%d%d", &n, &m) && (n || m)) {
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int j = 1; j <= m; j++) {
			scanf("%d", &b[j]);
			dp[0][j] = dp[1][j] = 0;
		}
		for (int i = 1; i <= n; i++) {
			k = !k;
			for (int j = 1; j <= m; j++)
				if (a[i] == b[j])
					dp[k][j] = max(dp[!k][j - 1] + 1, dp[k][j]);
				else
					dp[k][j] = max(dp[k][j - 1], dp[!k][j]);
		}
		printf("Twin Towers #%d\n", ++cas);
		printf("Number of Tiles : %d\n\n", dp[k][m]);
	}
	return 0;
}

