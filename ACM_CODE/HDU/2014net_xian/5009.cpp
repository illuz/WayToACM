/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        5009.cpp
*  Create Date: 2014-09-15 16:08:10
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 50010;

int a[N], b[N];
int f[N];
int last[N], dp[N];
int n, cnt;
map<int, int> mp;

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

void uni(int x, int y) {
	int t1 = find(x), t2 = find(y);
	if (t1 != t2)
		f[t2] = t1;
}

int main() {
	while (~scanf("%d", &n)) {
		repf (i, 1, n) {
			scanf("%d", &a[i]);
			b[i - 1] = a[i];
		}
		sort(b, b + n);
		cnt = unique(b, b + n) - b;

		mp.clear();
		repf (i, 0, cnt - 1) 
			mp[b[i]] = i;
		repf (i, 1, n)
			a[i] = mp[a[i]];
		memset(last, -1, sizeof(last));
		repf (i, 0, n)
			f[i] = i;

		dp[0] = 0;
		repf (i, 1, n) {
			if (last[a[i]] != -1) {
				uni(last[a[i]] - 1, last[a[i]]);
			}
			last[a[i]] = i;
			dp[i] = i;
			int num = 0;
			for (int j = i; j > 0; j = find(j - 1)) {
				num++;
				if (num * num >= dp[i]) break;
				int nxt = find(j - 1);
				dp[i] = min(dp[i], dp[nxt] + num * num);
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}

