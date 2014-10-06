/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1221.cpp
*  Create Date: 2014-10-03 10:52:28
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 510;

int n;
ll dp[N][N];

void produce() {
	repf (i, 1, N - 1)
		dp[0][i] = 1;
	dp[1][1] = 1;
	repf (i, 2, N - 1) {
		for (int j = i; j >= 1; j--)
			if (j > i / 2)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 2 * j][j] + dp[i][j + 1];
	}
}

int main() {
	// ios_base::sync_with_stdio(0);
	produce();
	while (~scanf("%d", &n) && n) {
		printf("%d %lld\n", n, dp[n][1]);
	}
	return 0;
}

