/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        H.cpp
*  Create Date: 2014-06-07 14:16:15
*  Descripton:   
*/

#include <cstdio>
#include <cstring>

const int N = 1e6 + 10;

int t, n;
int tab[N];

bool judge(int x) {
	int oth = 0;
	while (x) {
		if (x % 10 != 7)
			oth++;
		x /= 10;
	}
	return oth < 2;
}

void init() {
	for (int i = 1; i < N; i++) {
		tab[i] = tab[i - 1] + judge(i);
	}
}

int main() {
	init();
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", cas, tab[n]);
	}
	return 0;
}

