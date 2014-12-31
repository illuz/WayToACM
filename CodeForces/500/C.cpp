/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-12-30 23:48:19
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1510;

int n, m;
int w[N];
int b[N];

int main() {
	while (~scanf("%d%d", &n, &m)) {
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		for (int i = 1; i <= m; i++) {
			scanf("%d", &b[i]);
			set<int> tmp;
			for (int j = i - 1; j > 0 && b[j] != b[i]; j--)
				tmp.insert(b[j]);
			for (auto &j : tmp)
				ans += w[j];
		}
		cout << ans << endl;
	}
	return 0;
}

