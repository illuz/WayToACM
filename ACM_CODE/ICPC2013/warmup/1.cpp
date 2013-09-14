/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        a.cpp
*  Create Date: 2013-09-08 12:31:36
*  Descripton:  simulate 
*/

#include <cstdio>
#define rep(i, n) for (int i = 0; i < (n); i++)

const int MAXN = 11;
char str[MAXN][MAXN];
int cur = 0;

int main() {
	for (int i = 3; i <= 10; i++) {
		rep(j, i) rep(k, i) str[j][k] = ' ';
		rep(j, i)
			str[j][0] = 'a' + (cur++ % 26);
		for (int j = 1; j < i - 1; j++)
			str[i - j - 1][j] = 'a' + (cur++ % 26);
		rep(j, i)
			str[j][i - 1] = 'a' + (cur++ % 26);
		rep(j, i) {
		   	rep(k, i) putchar(str[j][k]);
			puts("");
		}
	}
	return 0;
}
