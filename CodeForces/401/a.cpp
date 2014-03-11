/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-03-11 20:38:15
*  Descripton:   
*/

#include <cstdio>
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define PIN(x) printf("%d\n",x)
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 0;
int n, x, sum, t;

int main()
{
	RII(n, x);
	rep (i, n) {
		RI(t);
		sum += t;
	}
	if (sum < 0) sum = -sum;
	PIN(sum / x + (sum % x ? 1 : 0));
	return 0;
}

