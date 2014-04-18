/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10453.cpp
*  Create Date: 2013-11-17 14:20:23
*  Descripton:  dp, inversal dp 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 0x7fffffff;
int dp[MAXN][MAXN];
char ch[MAXN];

int dfs(int l, int r) {
	if (l >= r) return dp[l][r] = 0;
	if (dp[l][r] != INF) return dp[l][r];
	if (ch[l] == ch[r])
		return dp[l][r] = min(dfs(l + 1, r - 1), min(dfs(l + 1, r), dfs(l, r - 1)) + 1);
	else
		return dp[l][r] = min(dfs(l + 1, r), dfs(l, r - 1)) + 1;

}

void output(int l, int r) {
	if (l > r) return;
	if (l == r) {
		putchar(ch[l]);
		return;
	}
	if (ch[l] == ch[r]) {
		putchar(ch[l]);
		output(l + 1, r - 1);
		putchar(ch[r]);
	} else if (dp[l][r] == dp[l + 1][r] + 1){
		putchar(ch[l]);
		output(l + 1, r);
		putchar(ch[l]);
	} else {
		putchar(ch[r]);
		output(l, r - 1);
		putchar(ch[r]);
	}
}

int main() {
	while (scanf("%s", ch) != EOF) {
		int len = strlen(ch);
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				dp[i][j] = INF;
		printf("%d ", dfs(0, len - 1));
		output(0, len - 1);
		puts("");
	}
	return 0;
}

