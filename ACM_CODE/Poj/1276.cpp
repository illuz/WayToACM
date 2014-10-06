/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1276.cpp
*  Create Date: 2014-10-02 22:39:27
*  Descripton:  dp, top to bottom
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 100010;

int dp[N];
int cash, n, nk[12], dk[12];

int main() {
	// ios_base::sync_with_stdio(0);
	while (~scanf("%d%d", &cash, &n)) {
		repf (i, 1, n) {
			scanf("%d%d", &nk[i], &dk[i]);
		}
		memset(dp, 0, sizeof(dp));
		repf (i, 0, n)
			dp[0] = 1;
		repf (i, 1, n) {
			for (int j = cash; j >= 0; j--) {
				if (!dp[j]) continue;
				int top = min(cash, j + dk[i] * nk[i]);
				for (int k = j + dk[i]; k <= top; k += dk[i])
					dp[k] = 1;
			}
		}
		for (int i = cash; i >= 0; i--)
			if (dp[i]) {
				printf("%d\n", i);
				break;
			}
	}
	return 0;
}

