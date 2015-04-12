/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2015-04-11 17:53:07
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;

int t, cas;
int n;
char lv[1010];
int pre, ans;

int main() {
    scanf("%d", &t);
    for (cas = 1; cas <= t; ++cas) {
        scanf("%d%s", &n, lv);
        pre = 0;
        ans = 0;
        for (int i = 0; lv[i]; ++i) {
            ans = max(ans, i - pre);
            pre += lv[i] - '0';
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

