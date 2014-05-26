/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1401.cpp
*  Create Date: 2014-05-26 20:20:53
*  Descripton:  also zoj2022
*/

#include <cstdio>

int n, t;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		while (n != 0) {
			ans += n / 5;
			n /= 5;
		}
		printf("%d\n", ans);
	}
	return 0;
}

