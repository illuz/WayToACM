/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2479.cpp
*  Create Date: 2014-09-25 10:38:38
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 1e5 + 10;

ll a[N], d1[N], ans, sum, mmax;
int t, n;

int main() {
	// ios_base::sync_with_stdio(0);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		mmax = -0x7fffffff;
		sum = 0;
		repf (i, 1, n) {
			scanf("%lld", &a[i]);
			sum += a[i];
			if (sum > mmax)
				mmax = sum;
			if (sum < 0)
				sum = 0;
			d1[i] = mmax;
		}
		sum = 0;
		ans = mmax = -0x7fffffff;
		for (int i = n; i > 0; i--) {
			sum += a[i];
			if (sum > mmax)
				mmax = sum;
			if (sum < 0)
				sum = 0;
			if (i != 1)
				ans = max(ans, d1[i - 1] + mmax);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

