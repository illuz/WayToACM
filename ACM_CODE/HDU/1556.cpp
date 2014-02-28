/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1556.cpp
*  Create Date: 2014-02-28 14:47:51
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define clr(a) memset(a,0,sizeof(a))

const int N = 1e5 + 10;

int n, a, b;
int c[N];

int lowbit(int x) { return x&-x; }

void add(int x, int d)
{
	while (x <= n) {
		c[x] += d;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x > 0) {
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}

int main() 
{
	while (RI(n) && n) {
		clr(c);
		rep (i, n) {
			RII(a, b);
			add(a, 1);
			add(b + 1, -1);
		}
		repf (i, 1, n) {
			printf("%d", query(i));
			if (i < n) printf(" ");
		}
		puts("");
	}
	return 0;
}

