/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        10673_bf.cpp
*  Create Date: 2014-04-22 15:31:26
*  Descripton:  brute force
*/

#include <cstdio>
#include <cmath>

int t;
int k, x;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &x, &k);
		if (x % k == 0) {
			printf("%d 0\n", k);
		}
		else {
			int f = floor(x * 1. / k);
			int c = ceil(x * 1. / k);
			for (int p = 0; p < k; p++) {
				if ((x - p * f) % c == 0) {
					printf("%d %d\n", p, (x - p * f) / c);
					break;
				}
			}
		}
	}
	return 0;
}

