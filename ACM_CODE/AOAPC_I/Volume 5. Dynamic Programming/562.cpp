/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        562.cpp
*  Create Date: 2013-09-21 20:24:49
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101000;

int a[MAXN];
bool dp[MAXN];

int main() {
	int t, n, sum;
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		dp[0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = sum; j >= a[i]; j--)
				if (dp[j - a[i]])
					dp[j] = 1;
		for (int i = sum / 2; i >= 0; i++)
			if (dp[i]) {
				printf("%d\n", abs(sum - 2 * i));
				break;
			}
	}
	return 0;
}

