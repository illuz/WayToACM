/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1003.cpp
*  Create Date: 2014-10-23 10:20:05
*  Descripton:   
*/

#define HDU
// don't forget to change I64d to I64d

#ifdef HDU
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <utility>
#include <cctype>
typedef __int64 ll;
#else	// c++11
#include <bits/stdc++.h>
typedef long long ll;
#endif

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 1e5 + 10;

int a[N];
int cnt[N];
int n, t;

vector<int> q;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		repf (i, 1, n) {
			scanf("%d", &a[i]);
		}
		memset(cnt, 0, sizeof(cnt));
		repf (i, 1, n) {
			// fenjie
			for (int j = 1; j * j <= a[i]; j++)
				if (a[i] % j == 0) {
					cnt[j]++;
					if (a[i] / j != j)
						cnt[a[i]/j]++;
				}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			q.clear();
			int m = a[i];
			for (int j = 2; j * j <= m; j++) 
				if (m % j == 0) {
					q.push_back(j);
					while (m % j == 0)
						m /= j;
				}
			if (m != 1)
				q.push_back(m);
			int sz = q.size();
			int len = (1 << sz);
			ll sum = 0;
			for (int j = 1; j < len; j++) {
				int flag = 0, u = 1;
				for (int k = 0; k < sz; k++)
					if ((1<<k) & j) {
						flag++;
						u *= q[k];
					}
				if (flag & 1)
					sum += cnt[u];
				else
					sum -= cnt[u];
			}
			if (sum) sum--;
			ans += sum * (n - 1 - sum);
		}
		ans /= 2;
		printf("%I64d\n", (ll)n * (n - 1) * (n - 2) / 6 - ans);
	}
	return 0;
}

