/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-07-09 19:03:21
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1001;

int n, m, dp[2][N], v[N];

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &v[j]);
				dp[i&1][j] = max(dp[(i+1)&1][j], dp[i&1][j-1]);
				if (v[j] > 0)
					dp[i&1][j] += v[j];
			}
		}
		printf("%d\n", dp[n&1][m]);
	}
	return 0;
}

