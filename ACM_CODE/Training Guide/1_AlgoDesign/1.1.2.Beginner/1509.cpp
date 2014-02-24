/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1509.cpp
*  Create Date: 2014-02-24 20:54:32
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#define rep(i,n) for(int i=0;i<(n);i++)
#define clr(a) memset(a,0,sizeof(a))

int k, len1, len2, vis[30], ans;
char s1[20], s2[50], leet[30][5];

void dfs(int p1, int p2) {
	int id, tlen;
	if (p1 == len1 && p2 == len2) {
		ans = 1;
		return;
	}
	if (ans) return;
	if (p1 > len1 || p2 > len2) return;
	id = s1[p1] - 'a';
	if (vis[id]) {
		tlen = strlen(leet[id]);
		if (p2 + tlen > len2) return;
		rep (i, tlen)
			if (leet[id][i] != s2[p2 + i]) return;
		dfs(p1 + 1, p2 + tlen);
	}
	else {
		vis[id] = 1;
		rep(i, k) {
			if (p2 + i >= len2) break;
			leet[id][i] = s2[p2 + i];
			leet[id][i + 1] = '\0';
			dfs(p1 + 1, p2 + i + 1);
		}
		vis[id] = 0;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		scanf("%s%s", s1, s2);
		len1 = strlen(s1);
		len2 = strlen(s2);

		clr(vis);
		clr(leet);
		ans = 0;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}

