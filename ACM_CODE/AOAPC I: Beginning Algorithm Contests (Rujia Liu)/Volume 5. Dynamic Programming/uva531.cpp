/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva531.cpp
*  Create Date: 2013-10-19 16:44:35
*  Descripton:  dp, LCS 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 101;

string s1[MAXN], s2[MAXN];
int n1, n2, t;
int dp[MAXN][MAXN], path[MAXN][MAXN];
bool flag;

void print(int a, int b) {
	while (path[a][b] == 2 || path[a][b] == 3)
		path[a][b] == 2 ? a-- : b--;
	if (a == 0 || b == 0) return;
	print(a - 1, b - 1);
	if (flag) printf(" ");
	else flag = 1;
	cout << s1[a];
};

int main() {
	n1 = n2 = 1;
	while (cin >> s1[n1++]) {
		while (cin >> s1[n1] && s1[n1] != "#")
			n1++;
		while (cin >> s2[n2] && s2[n2] != "#")
			n2++;
		memset(dp, 0, sizeof(dp));
		memset(path, 0, sizeof(path));
		flag = 0;
		n1--; n2--;
		for (int i = 1; i <= n1; i++)
			for (int j = 1; j <= n2; j++) {
				if (s1[i] == s2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1, path[i][j] = 1;
				else if (dp[i - 1][j] > dp[i][j - 1])
					dp[i][j] = dp[i - 1][j], path[i][j] = 2;
				else
					dp[i][j] = dp[i][j - 1], path[i][j] = 3;
			}
		print(n1, n2);
		n1 = n2 = 1;
		puts("");
	}
	return 0;
}
