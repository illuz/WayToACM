/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2411.cpp
*  Create Date: 2014-09-21 10:09:14
*  Descripton:  dp dfs
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 1<<11;

ll dp[12][N];
int h, w, tot;

// x-th row, y-th row, statue is d
void dfs(int x, int y, int d) {
	if (y > w)
		return;
	if (y == w) {		// the statue is completed
		if (x) {
			repf (k, 0, tot) {
				if ((d^k) == d - k)
					dp[x][d^k] += dp[x - 1][k];
			}
		} else			// if the first line
			dp[x][d]++;
	}
	// dfs to make the statue
	dfs(x, y + 1, (d<<1)|1);
	dfs(x, y + 2, (d<<2));
}

int main() {
	ios_base::sync_with_stdio(0);
	while (cin >> h >> w && (h || w)) {
		memset(dp, 0, sizeof(dp));
		tot = (1<<w) - 1;
		repf (i, 0, h - 1)
			dfs(i, 0, 0);
		cout << dp[h - 1][0] << endl;
	}
	return 0;
}

