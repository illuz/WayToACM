/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1141.cpp
*  Create Date: 2014-09-30 23:28:41
*  Descripton:  dp, print path
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 110;

int dp[N][N], path[N][N];
int len;
char s[N];

void print(int i, int j) {
	if (i > j)
		return;
	if (i == j) {
		if (s[i] == '(' || s[i] == ')')
			printf("()");
		if (s[i] == '[' || s[i] == ']')
			printf("[]");
	} else if (path[i][j] == -1) {
		putchar(s[i]);
		print(i + 1, j - 1);
		putchar(s[j]);
	} else {
		print(i, path[i][j]);
		print(path[i][j] + 1, j);
	}
}

int main() {
	// ios_base::sync_with_stdio(0);
	while (gets(s)) {
		len = strlen(s);
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		memset(path, -1, sizeof(path));
		repf (i, 0, len)
			dp[i][i] = 1, dp[i + 1][i] = 0;

		 repf (p, 1, len - 1) {
			 for (int i = 0, j = i + p; j < len; i++, j++) {
				 repf (k, i, j - 1) {
					 if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
						 dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
					 if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
						 path[i][j] = k;
						 dp[i][j] = dp[i][k] + dp[k + 1][j];
					 }
				 }
			 }
		 }

		 // printf("%d\n", dp[0][len - 1]);
		 print(0, len - 1);
		 puts("");
	}
	return 0;
}

