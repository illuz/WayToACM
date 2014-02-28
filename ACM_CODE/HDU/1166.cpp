/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1166.cpp
*  Create Date: 2014-02-28 09:26:35
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RS(x) scanf("%s",x)
#define PIN(x) printf("%d\n",x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define clr(a) memset(a,0,sizeof(a))

const int N = 5e4 + 10;

int t, n, c[N], id, val;
char op[6];

int lowbit(int x) {
	return x&(-x);
}

void add(int x, int d) {
	while (x <= n) {
		c[x] += d;
		x += lowbit(x);
	}
}

int query(int x) {
	int ret = 0;
	while (x > 0) {
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}

int main() {
	RI(t);
	rep (cas, t) {
		clr(c);
		RI(n);
		repf (i, 1, n) {
			RI(val);
			add(i, val);
		}
		printf("Case %d:\n", cas+1);
		while (RS(op) && op[0] != 'E') {
			RII(id, val);
			if (op[0] == 'A')
				add(id, val);
			else if (op[0] == 'S')
				add(id, -val);
			else 
				PIN(query(val) - query(id - 1));
		}
	}
	return 0;
}

