/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        D.cpp
*  Create Date: 2014-08-30 17:06:04
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1010;

int a[6][N], vis[N];
int n, k, v;
int dp[N], mmax;
vector<int> G[N];

bool check(int x, int y) {
	repf (i, 0, k - 1) {
		if (a[i][x] >= a[i][y])
			return 0;
	}
	return 1;
}

int dfs(int x, int d) {
	int ret = 0;
	if (vis[x])
		return vis[x];
	int sz = G[x].size();
	repf (i, 0, sz - 1) {
		ret = max(ret, dfs(G[x][i], d + 1));
	}
	return vis[x] = ret + 1;
}

int main() {
	while (cin >> n >> k) {
		memset(vis, 0, sizeof(vis));
		repf (i, 0, n)
			G[i].clear();
		repf (i, 0, k - 1) {
			repf (j, 1, n) {
				cin >> v;
				a[i][v] = j;
			}
		}
		repf (i, 1, n) {
			repf (j, 1, n) {
				if (check(i, j)) {
					G[i].push_back(j);
				}
			}
		}
		mmax = 0;
		repf (i, 1, n) {
			if (!vis[i])
				mmax = max(dfs(i, 0), mmax);
		}
		cout << mmax << endl;
	}
	return 0;
}

