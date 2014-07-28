/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2282.cpp
*  Create Date: 2014-06-04 09:24:27
*  Descripton:  comb 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;

char s[N];
int a[N], b[N];
int n, m;

void calc(char *s, int *tab) {
	int len = strlen(s), t = 1;
	for (int i = 0; i < len - 1; i++) {
		t *= 10;
		tab[0]  -= t;	// 提前扣掉多算的0
	}
	for (int i = 0; i < len; i++) {
		int tmp = s[i] - '0';
		for (int j = 0; j < tmp; j++) {
			tab[j] += t;
		}
		for (int j = 0; j < 10; j++) {
			tab[j] += tmp * ((len - i - 1) * t / 10);
		}
		tab[tmp] += atoi(s + i + 1) + 1;
		t /= 10;
	}
}

int main() {
	while (~scanf("%d%d", &n, &m) && (n || m)) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		if (n > m)
			swap(n, m);

		sprintf(s, "%d", n - 1);
		calc(s, a);
		sprintf(s, "%d", m);
		calc(s, b);
		for (int i = 0; i < N - 1; i++) {
			printf("%d ", b[i] - a[i]);
		}
		printf("%d\n", b[9] - a[9]);
	}
	return 0;
}

