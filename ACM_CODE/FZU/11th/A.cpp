/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-04-27 13:08:16
*  Descripton:   
*/

#include <cstdio>

int n, ans;

int main()
{
	while (~scanf("%d", &n)) {
		ans = (n - 1) / 7 * 2;
		if (n % 7 == 6)
			ans++;
		if (n % 7 == 0)
			ans += 2;
		printf("%d\n", ans);
	}
	return 0;
}

