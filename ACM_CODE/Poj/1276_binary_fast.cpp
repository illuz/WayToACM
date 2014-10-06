/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1276_binary_fast.cpp
*  Create Date: 2014-10-02 23:17:02
*  Descripton:  dp, binary optimal 
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
int cash, n, nk, dk;
int val[110], cnt;

int main() {
	// ios_base::sync_with_stdio(0);
	while (~scanf("%d%d", &cash, &n)) {
		cnt = 0;
		repf (i, 1, n) {
			scanf("%d%d", &nk, &dk);
			// change the nk to 1, 2, 4...
			int k = 1;
			while (nk >= k) {
				val[cnt++] = k * dk;
				nk -= k;
				k <<= 1;
			}
			if (nk)
				val[cnt++] = nk * dk;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		repf (i, 0, cnt - 1)
			for (int j = cash; j >= val[i]; j--) {
				if (dp[j - val[i]])
					dp[j] = 1;
			}
		int ans = cash;
		while (!dp[ans])
			ans--;
		printf("%d\n", ans);
	}
	return 0;
}

