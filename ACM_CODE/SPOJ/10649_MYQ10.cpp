/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        10649_MYQ10.cpp
*  Create Date: 2014-08-02 14:20:31
*  Descripton:  MYQ10, digit dp
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 50;

ll dp[N][N][2];		// dp[start][current][ismirror]
char bit[N], num[N];
int t, rec[N], len;

// the start pos, current pos, ismirror flag, is limit flag
// this function will use rec[] to record the prevent chosen numbers
ll dfs (int start, int cur, bool ismir, bool limit) {
	if (cur < 0)
		return ismir;
	if (!limit && dp[start][cur][ismir] != -1)
		return dp[start][cur][ismir];

	int mmax = limit ? bit[cur] - '0' : 9;
	ll ret = 0;
	repf (i, 0, mmax) {
		if (i == 0 || i == 1 || i == 8) {
			rec[cur] = i;
			if (start == cur && i == 0) {					// if have lead zero
				ret += dfs(start - 1, cur - 1, ismir, (limit && (i == mmax)));
			} else if (ismir && cur < (start + 1) / 2) {	// if ismirror and can judge
				ret += dfs(start, cur - 1, (i == rec[start - cur]), (limit && (i == mmax)));
			} else {
				ret += dfs(start, cur - 1, ismir, (limit && (i == mmax)));
			}
		}
	}
	return limit ? ret : dp[start][cur][ismir] = ret;
}

// check if first number is mirror
bool check() {
	repf (i, 0, len >> 1) {
		if (bit[i] != '0' && bit[i] != '1' && bit[i] != '8')
			return false;
		if  (bit[i] != bit[len - 1 - i])
			return false;
	}
	return true;
}

ll solve() {
	ll ans1, ans2;

	// first number
	scanf("%s", num);
	len = strlen(num);
	repf (i, 0, len - 1)
		bit[i] = num[len - 1 - i];
	bit[len] = 0;
	ans1 = dfs(len - 1, len - 1, 1, 1) - check();
//	cout << ans1 << endl;

	// second number
	scanf("%s", num);
	len = strlen(num);
	repf (i, 0, len - 1)
		bit[i] = num[len - 1 - i];
	bit[len] = 0;
	ans2 = dfs(len - 1, len - 1, 1, 1);
//	cout << ans2 << endl;

	cout << ans2 - ans1 << endl;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

