/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-08-03 19:04:50
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define clr(a) memset(a,0,sizeof(a))
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RD(x) scanf("%lf",&x)
#define RDD(x,y) scanf("%lf%lf",&x,&y)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d",x)
#define PIN(x) printf("%d\n",x)
#define PS(x) printf("%s",x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)

const int N = 2e5 + 10;

int t[N], cs[N];
int n, m, T, rr;

int main() {
	scanf("%d", &T);
	while (T-- ) {
		clr(t);
		clr(cs);
		RI(n);
		RI(m);
		rep (i, n) {
			RI(rr);
			t[rr]++;
		}
		int cur = 200000;
		repd (i, 200000, 0) {
			if (t[i] == 0)
				cur = i;
			cs[i] = cur;
		}
		rep (i, m) {
			RI(rr);
			printf("%d\n", cs[rr]);
		}
	}
	return 0;
}

