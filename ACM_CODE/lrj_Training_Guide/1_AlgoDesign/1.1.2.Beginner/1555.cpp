/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1555.cpp
*  Create Date: 2014-07-05 17:02:16
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 1500;

int n;
double a, b, H[N];

bool check(double h2) {
	H[1] = a;
	H[2] = h2;
	for (int i = 3; i <= n; i++) {
		H[i] = 2 * H[i - 1] + 2 - H[i - 2];
		if (H[i] < 0) {
			return false;
		}
	}
	b = H[n];
	return true;
}

int main() {
	while (~scanf("%d%lf", &n, &a)) {
		double l = 0, r = N, mid;

		while (r - l > 1e-8) {
			mid = (r + l) / 2;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}

		printf("%.2f\n", b);
	}
	return 0;
}

