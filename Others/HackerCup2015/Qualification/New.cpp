/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        New.cpp
*  Create Date: 2015-01-09 15:20:45
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 21;

int t, n, cas;
int ga, gb, gc;
int a[N], b[N], c[N];
int sa[N], sb[N], sc[N];

bool dfs(int i, int ra, int rb, int rc) {
	if (ra > sa[i] || rb > sb[i] || rc > sc[i])
		return false;
	if (!ra && !rb && !rc)
		return true;
	if (i >= n || ra < 0 || rb < 0 || rc < 0)
		return false;
	// choose cur
	if (dfs(i + 1, ra - a[i], rb - b[i], rc - c[i]))
		return true;
	// not choose
	if (dfs(i + 1, ra, rb, rc))
		return true;
}

int main() {
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d%d%d", &ga, &gb, &gc);
		scanf("%d", &n);
		int mina = ga + 1, minb = gb + 1, minc = gc + 1;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			mina = min(a[i], mina);
			minb = min(b[i], minb);
			minc = min(c[i], minc);
		}
		printf("Case #%d: ", cas);
		if (ga < mina || gb < minb || gc < minc) {
			puts("no");
			continue;
		}
		// get s
		sa[n - 1] = a[n -1];
		sb[n - 1] = b[n -1];
		sc[n - 1] = c[n -1];
		for (int i = n - 2; i >= 0; i--) {
			sa[i] = sa[i + 1] + a[i];
			sb[i] = sb[i + 1] + b[i];
			sc[i] = sc[i + 1] + c[i];
		}
		// dfs
		if (dfs(0, ga, gb, gc)) {
			puts("yes");
		} else {
			puts("no");
		}
	}
	return 0;
}

