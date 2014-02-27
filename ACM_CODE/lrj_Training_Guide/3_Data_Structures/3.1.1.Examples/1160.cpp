/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1160.cpp
*  Create Date: 2014-02-25 16:37:03
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#define RI(x) scanf("%d",&x)
#define PIN(x) printf("%d\n",x)
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 100010;

int f[N];
int a, b, ref;

int find(int x) {
	return f[x] != x ? f[x] = find(f[x]) : x;
}

int main() {
	rep (i, N) f[i] = i;
	ref = 0;
	while (~RI(a)) {
		if (a == -1) {
			PIN(ref);
			rep (i, N) f[i] = i;
			ref = 0;
			continue;
		}
		RI(b);
		a = find(a);
		b = find(b);
		if (a == b) ref++;
		else f[a] = b;
	}
	return 0;
}

