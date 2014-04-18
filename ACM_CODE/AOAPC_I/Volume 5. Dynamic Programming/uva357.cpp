/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva357.cpp
*  Create Date: 2013-09-21 19:49:14
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>

const int MAXN = 30100;
const int coin[5] = {1, 5, 10, 25, 50};

long long dp[MAXN];

int main() {
	int n;
	for (int i = 0; i < MAXN; i++) dp[i] = 1;
	for (int i = 1; i < 5; i++)
		for (int j = 0; j < 30000; j++)
			dp[j + coin[i]] += dp[j];
	while (scanf("%d", &n) != EOF)
		if (dp[n] != 1)
			printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
		else
			printf("There is only 1 way to produce %d cents change.\n", n);

	return 0;
}

