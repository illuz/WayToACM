/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2015-04-11 23:33:15
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1010;

int t;
int n;
int num[N], mmax;
int ans;
int table[N][N];

int main() {
    // pre
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= 1000; ++j) {
            // div j into i-size pieces
            table[j][i] = j / i - 1;
            if (j % i)
                ++table[j][i];
        }

    //
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
            mmax = max(mmax, num[i]);
        }
        ans = mmax;
        for (int i = 1; i < mmax; ++i) {
            int div = 0;
            for (int j = 0; j < n; ++j) {
                div += table[num[j]][i];
            }
            ans = min(ans, div + i);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

