/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10201.cpp
*  Create Date: 2013-11-17 10:18:50
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstdlib>

#define min(a, b) ((a) < (b) ? (a) : (b))

const int INF = 0x7fffffff;
int dp[110][210], d[210], p[210];
int t, n, l;
char ch[50];

int main() {
	gets(ch);
	sscanf(ch, "%d", &t);
	gets(ch);
	while (t--) {
		gets(ch);
		sscanf(ch, "%d", &l);
		n = 0;
		while (gets(ch) != NULL && ch[0] != '\0') {
			n++;
			sscanf(ch, "%d%d", &d[n], &p[n]);
			if (d[n] > l) n--;
		}

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= 200; j++)
				dp[i][j] = INF;
		dp[0][100] = 0;

		for (int i = 1; i <= n; i++) {
			int w = d[i] - d[i - 1];

			for (int j = 0; j + w <= 200; j++)
				if (dp[i - 1][j + w] != INF)
					dp[i][j] = dp[i - 1][j + w];

			for (int j = 0; j <= 200; j++)
				for (int k = 0; k <= j; k++)
					if (j - k + w <= 200 && dp[i - 1][j - k + w] != INF)
						dp[i][j] = min(dp[i][j], dp[i - 1][j - k + w] + k * p[i]);
		}

		if (l - d[n] > 100 || dp[n][100 + l - d[n]] == INF)
			puts("Impossible");
		else
			printf("%d\n", dp[n][100 + l - d[n]]);
		if (t) puts("");
	}
	return 0;
}

