/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-12-30 23:19:58
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 310;

int n;
int a[N];
char m[N];
int fa[N];

int Find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = Find(fa[x]);
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i <= n; i++)
			fa[i] = i;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) {
			scanf("%s", m);
			for (int j = 0; j < n; j++)
				if (m[j] == '1') {
					int ta = Find(i), tb = Find(j);
					fa[ta] = fa[tb];
				}
		}
		vector<int> ind[N], num[N];
		for (int i = 0; i < n; i++) {
			ind[Find(i)].push_back(i);
			num[Find(i)].push_back(a[i]);
		}
		for (int i = 0; i < n; i++) {
			sort(num[i].begin(), num[i].end());
			int sz = ind[i].size();
			for (int j = 0; j < sz; j++)
				a[ind[i][j]] = num[i][j];
		}
		printf("%d", a[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", a[i]);
		puts("");
	}
	return 0;
}

