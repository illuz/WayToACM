/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-06-04 10:41:09
*  Descripton:   
*/

#include <cstdio>

const int N = 100010;

int vis[N], n, t;

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &t);
		vis[t]++;
	}
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0)
			printf("%d\n", i);
	return 0;
}

