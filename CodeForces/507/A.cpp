/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2015-01-24 00:01:56
*  Descripton:  sort
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 110;

int n, k;
pair<int, int> a[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	int ans = 0, sum = 0;
	while (ans < n && sum + a[ans].first <= k)
		sum += a[ans++].first;
	printf("%d\n", ans);
	if (ans) {
		printf("%d", a[0].second);
		for (int i = 1; i < ans; i++)
			printf(" %d", a[i].second);
		printf("\n");
	}
	return 0;
}

