/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1260.cpp
*  Create Date: 2014-10-03 11:44:25
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 110;

int t, n;
int a, p, sum[N], dp[N];

int main() {
	// ios_base::sync_with_stdio(0);
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d", &n);
		repf (i, 1, n) {
			scanf("%d%d", &a, &p);
			sum[i] = sum[i - 1] + a;
			dp[i] = dp[i - 1] + (a + 10) * p;
			repf (j, 0, i - 1) {
				dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j] + 10) * p);
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}

