/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3555.cpp
*  Create Date: 2014-07-26 16:04:07
*  Descripton:  digit dp 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define RI(x) scanf("%d",&x)
#define PIN(x) printf("%d\n",x)

typedef long long ll;

const int N = 30;
ll z[N] = {1};

int t;
int bit[N];
ll dp[N][2], n;

ll dfs(int len, bool is4, bool ismax) {
	if (len == 0)
		return 0;
	if (!ismax && dp[len][is4] >= 0)
		return dp[len][is4];

	ll cnt = 0;
  	int mmax = ismax ? bit[len] : 9;
	for (int i = 0; i <= mmax; i++) {
		if (is4 && i == 9) {
			cnt += ismax ? n % z[len-1] + 1 : z[len-1];
		} else {
			cnt += dfs(len - 1, i == 4, ismax && bit[len] == i);
		}
	}

	return ismax ? cnt : dp[len][is4] = cnt;
}

ll solve(ll n) {
	int len = 0;
	while (n) {
		bit[++len] = n % 10;
		n /= 10;
	}
	bit[len + 1] = 0;
	return dfs(len, false, true);
}

int main() {
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < N; i++) {
		z[i] = z[i - 1] * 10;
	}
	RI(t);
	while (t--) {
		scanf("%I64d", &n);
		printf("I64d\n", solve(n));
//		cin >> n;
//		cout << solve(n) << endl;
	}
	return 0;
}

