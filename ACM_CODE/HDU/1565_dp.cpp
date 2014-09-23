/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1565_dp.cpp
*  Create Date: 2014-09-19 23:30:19
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 1<<21;

int n, st[N], stn;
int dp[2][N];
int ans, g[25][25];

void pre() {
	repf (i, 0, (1<<20)) {
		if (i & (i<<1))
			continue;
		else
			st[stn++] = i;
	}
}

void solve() {
	if (n == 0) {
		cout << 0 << endl;
		return;
	}
	int tot = 1<<n;
	ans = 0;
	// first line
	for (int i = 0; st[i] < tot; i++) {
		dp[0][i] = 0;
		repf (j, 0, n - 1)
			if (st[i]&(1<<j))
				dp[0][i] += g[0][j];
		ans = max(ans, dp[0][i]);
	}
	// 2~n line
	repf (i, 1, n - 1) {
		for (int j = 0; st[j] < tot; j++) {
			int tmp = 0;
			dp[i&1][j] = 0;
			// can get tmp value
			repf (k, 0, n - 1) {
				if (st[j]&(1<<k))
					tmp += g[i][k];
			}
			for (int k = 0; st[k] < tot; k++) {
				if (!(st[j]&st[k]))
					dp[i&1][j] = max(dp[i&1][j], tmp + dp[!(i&1)][k]);
			}
			ans = max(ans, dp[i&1][j]);
		}
	}
	cout << ans << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	pre();
	while (cin >> n) {
		repf (i, 0, n - 1) repf (j, 0, n - 1)
			cin >> g[i][j];
		solve();
	}
	return 0;
}

