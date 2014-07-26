/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2089_dfs.cpp
*  Create Date: 2014-07-26 15:21:12
*  Descripton:  dfs version 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define RII(x,y) scanf("%d%d",&x,&y)
#define PIN(x) printf("%d\n",x)

const int N = 10;

int bits[N], dp[N][2];	// dp[i][is6] is the number of i-len digits with (if prevent number is 6), its digits are from 0-9

// the rest length, Is the prevent digit 6, Is the digit max
int dfs(int len, bool is6, bool ismax) {
	if (len == 0)
		return 1;
	if (!ismax && dp[len][is6] >= 0)		// dp
		return dp[len][is6];

	int cnt = 0, mmax = (ismax? bits[len] : 9);
	for (int i = 0; i <= mmax; i++) {
		if (i == 4 || is6 && i == 2)	// unluck digit
			continue;
		cnt += dfs(len - 1, i == 6, ismax && i == mmax);
	}

	return ismax ? cnt : dp[len][is6] = cnt;	// remember the result
}

int solve(int num) {
	int len = 0;
	while (num) {
		bits[++len] = num % 10;
		num /= 10;
	}

	return dfs(len, false, true);
}

int main() {
	int n, m;
	memset(dp, -1, sizeof(dp));
	while (~scanf("%d%d", &n, &m) && (n || m)) {
		PIN(solve(m) - solve(n - 1));
	}
	return 0;
}

