/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        954.cpp
*  Create Date: 2014-05-26 20:31:42
*  Descripton:   
*/

#include <cstdio>

int n, ans;

int main()
{
	while (~scanf("%d", &n)) {
		ans = 0;
		while (n != 0) {
			ans += n / 2;
			n /= 2;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}

