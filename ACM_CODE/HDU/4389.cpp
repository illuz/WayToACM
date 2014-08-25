/*
*  Author:      iintuz <iiintuzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        4389.cpp
*  Create Date: 2014-08-23 15:56:00
*  Descripton:  digit dp
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 82;

// dp[pos][sum][MOD][rest]
int dp[11][N][N][N], ans, sum;
int t, n, m, bit[11], len;

int dfs(int pos, int sum, int mod, int rest, int limit) {
	if (sum > mod || mod > 81)
		return 0;
	if (pos < 0)
		return sum == mod && rest == 0;
	if (!limit && dp[pos][sum][mod][rest] != -1) {
		return dp[pos][sum][mod][rest];
	}
	int mmax = limit ? bit[pos] : 9;
	int res = 0;
	repf (i, 0, mmax) {
		res += dfs(pos - 1, sum + i, mod, (rest * 10 + i) % mod, limit && i == mmax);
	}
	return limit ? res : dp[pos][sum][mod][rest] = res;
}

int solve(int x) {
	ans = 0;
	for (len = 0; x; bit[len++] = x%10, x /= 10);
	bit[len] = 0;
	repf (i, 1, len * 9) {
		ans += dfs(len - 1, 0, i, 0, 1);
	}
	return ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d%d", &n, &m);
		printf("Case %d: %d\n", cas, solve(m) - solve(n - 1));
	}
	return 0;
}

