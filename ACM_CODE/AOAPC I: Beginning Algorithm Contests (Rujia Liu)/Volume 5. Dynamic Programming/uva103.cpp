/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva103.cpp
*  Create Date: 2013-09-12 19:32:36
*  Descripton:  dp 
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100;

struct Box {
	int dem;
	int e[30];
	void Sort() {
		sort(e, e + dem);
	}
	bool operator < (const Box& a) const {
		for (int i = 0; i < dem; i++)
			if (e[i] >= a.e[i])
				return false;
		return true;
	}
} b[MAXN];
int big[MAXN][MAXN], k, t;
int dp[MAXN];

int solve(int i) {
	if (dp[i] > 0) return dp[i];
	dp[i] = 1;
	for (int j = 0; j < t; j++)
		if (big[i][j])
			dp[i] = max(dp[i], solve(j) + 1);
	return dp[i];
}

void output(int i) {
	for (int j = 0; j < t; j++)
		if (big[i][j] && dp[i] == dp[j] + 1) {
			printf(" %d", j + 1);
			output(j);
			break;
		}
}

int main() {
	while (scanf("%d%d", &t, &k) != EOF) {
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < k; j++) {
				b[i].dem = k;
				scanf("%d", &b[i].e[j]);
			}
			b[i].Sort();
		}
		memset(big, 0, sizeof(big));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < t; i++)
			for (int j = 0; j < t; j++)
				if (i != j && b[i] < b[j])
					big[i][j] = 1;
		for (int i = 0; i < t; i++)
			solve(i);
		int tt = 0;
		for (int i = 0; i < t; i++)
			if (dp[i] > dp[tt])
				tt = i;
		printf("%d\n", dp[tt]);
		printf("%d", tt + 1);
		output(tt);
		printf("\n");
	}
	return 0;
}
