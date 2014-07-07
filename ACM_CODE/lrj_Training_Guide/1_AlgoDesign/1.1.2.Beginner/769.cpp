/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        769.cpp
*  Create Date: 2014-07-07 09:32:33
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int beg = 2 * n + 2, div = 1;
		for (int i = 0; i < 2 * n - 2; i++) {
			printf("%d", beg++);
			div = !div;
			for (int j = 1; j <= n; j++) {
				int tmp = i / 2 * n + j;
				if (j % 2 == div) {
					printf(" %d", tmp);
				}
			}
			puts("");
		}
		if (beg % 2 == 0) {
			beg++;
		}
		for (int i = n*(n-1)+1; i <= n*n-1; i++) {
			printf("%d %d\n", beg, i);
			beg += 2;
		}
		if (t) {
			puts("");
		}
	}
	return 0;
}

