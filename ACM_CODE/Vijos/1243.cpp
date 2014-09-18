/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1243.cpp
*  Create Date: 2014-09-16 22:44:10
*  Descripton:  vijos 1243, dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 100005;

int cost[6][N];
int m, n, K, l, r, ans;
int dp[6][N];
deque<int> dq[6][6];

inline int calc(int i, int j, int k) {
	return dp[k][j] - cost[i][j];
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> m >> n >> K >> l;
	// init sum of time
	repf (i, 1, n)
		repf (j, 1, m) {
			cin >> r;
			cost[i][j] = cost[i][j - 1] + r;
		}
	memset(dp, 0x7f, sizeof(dp));
	repf (i, 1, n)
		dp[i][0] = 0;

	repf (j, 0, m) {
		// dp
		repf (i, 1, n)
			repf (k, 1, n) {
				if (i == k) continue;
				int a = 0, b = 0;
				if (!dq[i][k].empty())
					a = calc(i, dq[i][k].front(), k);
				b = cost[i][j] + K;
				dp[i][j] = min(dp[i][j], a + b);
			}

		// push the j to the back of deques
		repf (i, 1, n)
			repf (k, 1, n) {
				if (i == k) continue;
				while (!dq[i][k].empty() &&
						(calc(i, dq[i][k].back(), k) >= calc(i, j, k)))
					dq[i][k].pop_back();
				dq[i][k].push_back(j);

				while (!dq[i][k].empty() && (j - dq[i][k].front()) > l)
					dq[i][k].pop_front();
			}
	}

	ans = 0x7ffffff;
	repf (i, 1, n)
		ans = min(ans, dp[i][m]);
	cout << ans - K << endl;
	return 0;
}

