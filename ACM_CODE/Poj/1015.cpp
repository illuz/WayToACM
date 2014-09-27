/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1015.cpp
*  Create Date: 2014-09-26 09:40:48
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 810;
const int INF = 0x7fffffff;

int pa[21][N], dp[21][N];
int n, m, OFF, cas;
int d[210], p[210];
int ans[21];

void init() {
	memset(dp, -1, sizeof(dp));
	memset(pa, -1, sizeof(pa));
	OFF = m * 20;		// offset
	repf (i, 1, n) {
		scanf("%d%d", &p[i], &d[i]);
	}
}

void solve() {
	dp[0][OFF] = 0;		// start state
	repf (i, 0, m - 1) {
		repf (j, 0, OFF * 2) {
			// if cannot arrive the state then pass
			if (dp[i][j] == -1)
				continue;
			// change state
			repf (k, 1, n) {
				if (dp[i][j] + p[k] + d[k] <= dp[i + 1][j + p[k] - d[k]])
					continue;
				// find the way back
				int ri = i, rj = j;
				while (ri > 0 && rj > 0) {
					int pre = pa[ri][rj];
					if (pre == k)	// k is used
						break;
					ri--;
					rj -= (p[pre] - d[pre]);
				}
				if (ri == 0) {	// there is a way
					dp[i + 1][j + p[k] - d[k]] = dp[i][j] + p[k] + d[k];
					pa[i + 1][j + p[k] - d[k]] = k;
				}
			}
		}
	}
}

void output() {
	int t, pans, dans;
	// get the min diff and max sum
	repf (i, 0, OFF) {
		if (dp[m][OFF - i] >= 0 || dp[m][OFF + i] >= 0) {
			if (dp[m][OFF - i] > dp[m][OFF + i])
				t = OFF - i;
			else
				t = OFF + i;
			break;
		}
	}
	pans = (dp[m][t] - (OFF - t)) / 2;
	dans = (dp[m][t] + (OFF - t)) / 2;

	printf("Jury #%d\n", cas++);
	printf("Best jury has value %d for prosecution and value %d for defence:\n", pans, dans);
	repf (i, 0, m - 1) {
		ans[i] = pa[m - i][t];
		t -= p[ans[i]] - d[ans[i]];
	}
	sort(ans, ans + m);
	repf (i, 0, m - 1) {
		printf(" %d", ans[i]);
	}
	puts("\n");
}

int main() {
	// ios_base::sync_with_stdio(0);
	cas = 1;
	while (~scanf("%d%d", &n, &m) && (n || m)) {
		init();
		solve();
		output();
	}
	return 0;
}

