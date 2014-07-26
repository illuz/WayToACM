/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2089_bf.cpp
*  Create Date: 2014-03-31 20:28:46
*  Descripton:  brute force way 
*/

#include <cstdio>
#define RII(x,y) scanf("%d%d",&x,&y)
#define PIN(x) printf("%d\n",x)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 1000010;

int f[N], n, m;

bool check(int r) {
	while (r) {
		if (r % 10 == 4) return false;
		if (r % 100 == 62) return false;
		r /= 10;
	}
	return true;
}

void init() {
	repf (i, 1, 1000000)
		if (check(i))
			f[i] = f[i - 1] + 1;
		else
			f[i] = f[i - 1];
}

int main()
{
	init();
	while (RII(n, m) && (n || m)) {
		PIN(f[m] - f[n - 1]);
	}
	return 0;
}

