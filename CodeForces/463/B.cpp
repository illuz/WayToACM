/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        B.cpp
*  Create Date: 2014-08-27 12:45:06
*  Descripton:  tree dp
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1e5 + 10;
const int MOD = 1000000007;

vector<int> g[N];
int color[N];
ll dp[N][2];
int n, tmp;

void dfs(int u) {
	dp[u][color[u]] = 1;
	int sz = g[u].size();
	repf (i, 0, sz - 1) {
		int v = g[u][i];
		dfs(v);
		ll u0 = dp[u][0], u1 = dp[u][1], v0 = dp[v][0], v1 = dp[v][1];
		dp[u][0] = u0 * (v0 + v1) % MOD;
		dp[u][1] = (u0 * v1 + u1 * (v0 + v1)) % MOD;
	}
}

int main() {
	while (~scanf("%d", &n)) {
		repf (i, 0, n - 1)
			g[i].clear();
		repf (i, 1, n - 1) {
			scanf("%d", &tmp);
			g[tmp].push_back(i);
		}
		repf (i, 0, n - 1) {
			scanf("%d", &color[i]);
		}
		memset(dp, 0, sizeof(dp));
		dfs(0);
		cout << dp[0][1] << endl;
	}
	return 0;
}

