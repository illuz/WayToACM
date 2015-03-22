/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1024.cpp
*  Create Date: 2015-03-22 10:16:35
*  Descripton:  Max sum of k segments.
*               dp[i][j] means the maxsum of i segments in num[0~j]
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1000010;

int n, m, mmax, num[N];
int dp[N], pre[N];

int main() {
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &num[i]);
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= m; ++i) {
            mmax = INT_MIN;
            for (int j = i; j <= n; ++j) {
                dp[j] = max(dp[j - 1], pre[j - 1]) + num[j];
                pre[j - 1] = mmax;
                mmax = max(mmax, dp[j]);
            }
        }
        printf("%d\n", mmax);
    }
    return 0;
}

