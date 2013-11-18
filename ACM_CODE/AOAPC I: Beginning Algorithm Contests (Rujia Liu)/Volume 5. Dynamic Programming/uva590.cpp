/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva590.cpp
*  Create Date: 2013-11-03 15:01:00
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 0x7fffffff;

int day[15][15];
int price[15][15][35];
int dp[15][1005];
int n, k;

int main() {
	int cas = 0;

	while (scanf("%d%d", &n, &k) && (n || k)) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j) {
					scanf("%d", &day[i][j]);
					for (int d = 1; d <= day[i][j]; d++)
						scanf("%d", &price[i][j][d]);
				}

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k ; j++)
				dp[i][j] = MAX;
		dp[1][0] = 0;

		for (int d = 1; d <= k; d++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (i != j) {
						int q = (d - 1) % day[j][i] + 1;
						if (price[j][i][q] && dp[j][d - 1] != MAX)
							dp[i][d] = min(dp[i][d], dp[j][d - 1] + price[j][i][q]);
					}

		printf("Scenario #%d\n", ++cas);
		if (dp[n][k] != MAX)
			printf("The best flight costs %d.\n\n", dp[n][k]);
		else
			printf("No flight possible.\n\n");
	}
	return 0;
}
