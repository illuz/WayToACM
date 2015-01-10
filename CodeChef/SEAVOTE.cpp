/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        SEAVOTE.cpp
*  Create Date: 2015-01-10 14:56:56
*  Descripton:  Greedy
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 10010;

int n, t;
int a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool ok = true;
		int sum = 0, zero = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] > 100)
				ok = false;
			sum += a[i];
			if (a[i] == 0)
				++zero;
		}

		if (sum < 100 || sum >= n - zero + 100)
			ok = false;
		if (ok)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

