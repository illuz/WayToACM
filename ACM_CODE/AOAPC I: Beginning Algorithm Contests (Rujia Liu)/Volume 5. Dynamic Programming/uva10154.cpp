/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10154.cpp
*  Create Date: 2013-11-09 11:13:55
*  Descripton:  dp
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 6000;
const int MAX = 0x7ffffff;

struct Turtle {
	int wei, stg;
} t[MAXN];

int w, s, n, dp[MAXN];

bool cmp(const Turtle &a, const Turtle &b) {
	if (a.stg != b.stg)
		return a.stg < b.stg;
	return a.wei < b.wei;
}

int main() {
	while (scanf("%d%d", &w, &s) != EOF)
		if (s >= w)
			t[++n].wei = w, t[n].stg = s;

	sort(t + 1, t + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		dp[i] = MAX;

	int ans = (n ? 1 : 0);
	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 1; j--) {
			if (t[i].stg >= dp[j - 1] + t[i].wei)
				dp[j] = min(dp[j], dp[j - 1] + t[i].wei);
			if (dp[j] < MAX)
				ans = max(ans, j);
		}

	printf("%d\n", ans);

	return 0;
}

