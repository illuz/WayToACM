/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11825.cpp
*  Create Date: 2014-06-27 20:43:48
*  Descripton:  sub set/ dp/ numeric 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 16;

int n, m, t, mask[N], cover[1<<N], dp[1<<N], tot;

int main() {
	int cas = 0;
	while (~scanf("%d", &n) && n) {
		// input
		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			mask[i] = (1 << i);
			while (m--) {
				scanf("%d", &t);
				mask[i] |= (1 << t);
			}
		}

		// get the union set of cover
		for (int S = 0; S < (1 << n); S++) {
			cover[S] = 0;
			for (int i = 0; i < n; i++) {
				if (S & (1 << i)) {
					cover[S] |= mask[i];
				}
			}
		}

		// dp
		dp[0] = 0;
		tot = (1 << n) - 1;
		for (int S = 1; S < (1 << n); S++) {
			dp[S] = 0;
			for (int S0 = S; S0; S0 = (S0 - 1)&S) {
				if (cover[S0] == tot) {
					dp[S] = max(dp[S], dp[S^S0] + 1);
				}
			}
		}

		printf("Case %d: %d\n", ++cas, dp[tot]);
	}
	return 0;
}

