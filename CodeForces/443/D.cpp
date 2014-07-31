#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

double a[101];
double dp[101];

bool cmp(double x,double y) {
    return x > y;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    sort(a, a + n, cmp);
    dp[0] = a[0];
    double ans = a[0];
    for(int i = 1; i < n; i++) {
        double x = 1;
        for(int j = 0; j < i; j++)
            x *= 1 - a[j];
        dp[i] = (dp[i-1] * (1 - a[i]) + x * a[i]);
        ans = max(ans, dp[i]);
    }
    printf("%.9lf\n", ans);
    return 0;
}
