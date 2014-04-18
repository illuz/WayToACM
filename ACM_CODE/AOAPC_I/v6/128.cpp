/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        128.cpp
*  Create Date: 2014-04-17 21:01:44
*  Descripton:   
*/

#include <cstdio>
#include <cmath>

const int N = 1030;
const int MOD = 34943;
const char v[] = "0123456789ABCDEF";

char s[N];
int x, y, ans[5];

int main()
{
	while (gets(s)) {
		if (s[0] == '#' && s[1] == 0)
			break;
		x = 0;
		for (int i = 0; s[i]; i++)
			x = (x * 256 + s[i]) % MOD;
		x = (x * 256 % MOD) * 256 % MOD;

		y = (MOD - x) % MOD;
		for (int i = 0; i < 4; i++) {
			ans[i] = y % 16;
			y /= 16;
		}
		printf("%c%c %c%c\n", v[ans[3]], v[ans[2]], v[ans[1]], v[ans[0]]);
	}
	return 0;
}

