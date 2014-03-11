/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        c.cpp
*  Create Date: 2014-03-11 21:25:21
*  Descripton:   
*/

#include <cstdio>
#define RII(x,y) scanf("%d%d",&x,&y)
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 1e6 + 10;
int n, m;

int main()
{
	RII(n, m);
	if (m >= n - 1 && m <= ((n+1)<<1)) {
		m -= (n - 1);
		if (m >= 2)
			printf("110"), m -= 2;
		else if (m == 1)
			printf("10"), m--;
		else
			printf("0");
		rep (i, n - 1) {
			if (m)
				printf("110"), m--;
			else
				printf("10");
		}
		rep (i, m) printf("1");
		puts("");
	}
	else
		puts("-1");
	return 0;
}

