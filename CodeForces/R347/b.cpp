/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        b.cpp
*  Create Date: 2013-09-20 23:43:46
*  Descripton:  b 
*/

#include <cstdio>
#define rep(i, n) for (int i = 0; i < (n); i++)

const int MAXN = 100100;
int a[MAXN], n, cnt;
int rec[MAXN], r;

int main() {
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &a[i]);
		if (a[i] == i)
			cnt++;
		else
			rec[r++] = i;
	}
	int cg = r > 0 ? 1 : 0;
	rep(i, r)
		if (a[a[rec[i]]] == rec[i]) {
			cg = 2;
			break;
		}
	printf("%d\n", cnt + cg);
	return 0;
}


