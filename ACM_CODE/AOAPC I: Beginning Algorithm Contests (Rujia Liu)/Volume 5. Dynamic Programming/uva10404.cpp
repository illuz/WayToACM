/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10404.cpp
*  Create Date: 2013-10-20 21:34:01
*  Descripton:  dp, game theory 
*/

#include <cstdio>
//#include <cstring>

const int MAXN = 1e6 + 1;

bool dp[MAXN];
int n, m, a[11];

int main() {
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d", &a[i]);
		dp[0] = false;
		for (int i = 1; i <= n; i++) {
			bool flag = false;
			for (int j = 0; j < m; j++)
				if (i >= a[j] && !dp[i - a[j]]) {
					flag = true;
					break;
				}
			dp[i] = flag;
		}
		if (dp[n]) puts("Stan wins");
		else puts("Ollie wins");
	}
	return 0;
}

