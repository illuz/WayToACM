/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11121.cpp
*  Create Date: 2014-04-22 16:15:23
*  Descripton:  Base -2 
*/

#include <cstdio>
#include <cstring>

const int N = 1000;

int t, n;
int r[N];

void calc(int n, int bas)
{
	memset(r, 0, sizeof(r));
	int cnt = 0;
	while (n) {
		if (n % bas >= 0) {
			r[cnt++] = n % bas;
			n /= bas;
		} else {
			r[cnt++] = n % bas - bas;
			n = n / bas + 1;
		}
	}
	if (cnt <= 1)
		printf("%d\n", r[0]);
	else {
		for (int i = cnt - 1; i >= 0; i--)
			printf("%d", r[i]);
		puts("");
	}
}

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		printf("Case #%d: ", cas);
		calc(n, -2);
	}
	return 0;
}

