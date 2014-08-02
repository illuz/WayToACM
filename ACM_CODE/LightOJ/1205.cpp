/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1205.cpp
*  Create Date: 2014-08-02 16:21:04
*  Descripton:  digit dp, palindrome 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 20;
int t, len, rec[N], bit[N];
ll a, b, dp[N][N][2];

ll dfs (int start, int cur, bool ismir, bool limit) {
	if (cur < 0)
		return ismir;
	if (!limit && dp[start][cur][ismir] != -1)
		return dp[start][cur][ismir];

	int mmax = limit ? bit[cur] : 9;
	ll ret = 0;
	repf (i, 0, mmax) {
		rec[cur] = i;
		if (start == cur && i == 0) {					// if have lead zero
			ret += dfs(start - 1, cur - 1, ismir, (limit && (i == mmax)));
		} else if (ismir && cur < (start + 1) / 2) {	// if ismirror and can judge
			ret += dfs(start, cur - 1, (i == rec[start - cur]), (limit && (i == mmax)));
		} else {
			ret += dfs(start, cur - 1, ismir, (limit && (i == mmax)));
		}
	}
	return limit ? ret : dp[start][cur][ismir] = ret;
}

ll calc(ll n) {
	len = 0;
	while (n) {
		bit[len++] = n % 10;
		n /= 10;
	}
	bit[len] = 0;
	return dfs(len - 1, len - 1, 1, 1);
}

bool check() {
	repf (i, 0, len / 2 - 1) {
		if (bit[i] != bit[len - 1 - i])
			return false;
	}
	return true;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &t);
	int cas = 1;
	while (t--) {
		scanf("%lld %lld", &a, &b);
		if (a < b) swap(a, b);
		printf("Case %d: %lld\n", cas++, calc(a) - calc(b) + check());
	}
	return 0;
}

