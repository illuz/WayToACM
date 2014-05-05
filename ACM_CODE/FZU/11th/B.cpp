/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-04-27 13:22:23
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;

int t, m, n, x[N], s[N];

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
			s[i] = s[i - 1] + x[i];
		}
		int ans = 0, mmax;
		for (int i = 1; i <= m; i++)
			ans += i * x[i];
		mmax = ans;
		for (int i = 2; i + m - 1 <= n; i++) {
			ans -= (s[i + m - 2] - s[i - 2]);
			ans += x[i + m - 1] * m;
			mmax = max(ans, mmax);
		}
		printf("%d\n", mmax);
	}
	return 0;
}

