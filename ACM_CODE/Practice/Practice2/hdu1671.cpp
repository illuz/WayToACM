/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        hdu1671.cpp
*  Create Date: 2013-10-15 22:30:11
*  Descripton:  hdu1671, binary tree
*/

#include <cstdio>
#include <cstring>

const int MAXN = 400100;

struct P {
	int next[10];
	bool haveSon, isLeaf;
} p[MAXN];

int t, n, cnt, len;
char num[41];
bool ok;

void solve(int d, int r) {
	if (d == len) {
		if (p[r].haveSon == 1 || p[r].isLeaf == 1) ok = false;
		p[r].isLeaf = 1;
		return;
	}
	if (p[r].isLeaf == 1) {
		ok = false;
		return;
	}
	p[r].haveSon = 1;
	if (p[r].next[num[d] - '0'] == 0)
		p[r].next[num[d] - '0'] = ++cnt;
	solve(d + 1, p[r].next[num[d] - '0']);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		ok = true;
		cnt = 0;
		memset(p, 0, sizeof(p));
		scanf("%d", &n);
		while (n--) {
			scanf("%s", num);
			if (!ok) continue;
			len = strlen(num);
			solve(0, 0);
		}
		if (ok) puts("YES");
		else puts("NO");
	}
}
