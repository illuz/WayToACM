/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1329.cpp
*  Create Date: 2014-02-27 15:51:10
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RS(x) scanf("%s",x)
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 20014;

int f[N], d[N];
int t, n, u, v;
char op[2];

int find(int x) {
	if (f[x] != x) {
		int r = find(f[x]);
		d[x] += d[f[x]];
		return f[x] = r;
	}
	return x;
}

int main() {
	RI(t);
	while (t--) {
		RI(n);
		rep (i, n) f[i] = i, d[i] = 0;
		while (RS(op) && op[0] != '0') {
			if (op[0] == 'E') {
				RI(u);
				find(u);
				printf("%d\n", d[u]);
			}
			else {
				RII(u, v);
				f[u] = v;
				d[u] = abs(u - v) % 1000;
			}
		}
	}
	return 0;
}

