/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10739.cpp
*  Create Date: 2013-11-08 15:20:51
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>

#define min(a, b) ((a) < (b) ? (a) : (b))

const int MAXN = 1010;

int dp[MAXN][MAXN];
char ch[MAXN];
int t, cas;

int main() {
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++) {
		scanf("%s", ch);
		int len = strlen(ch);

		for (int i = 0; i < len; i++)
			dp[i][i] = 0;

		for (int i = len - 1; i >= 0; i--)
			for (int j = i + 1; j < len; j++)
				if (ch[i] == ch[j])
					dp[i][j] = dp[i + 1][j - 1];
				else
					dp[i][j] = min(min(dp[i + 1][j], dp[i + 1][j - 1]), dp[i][j - 1]) + 1;

		printf("Case %d: %d\n", cas, dp[0][len - 1]);
	}
	return 0;
}

