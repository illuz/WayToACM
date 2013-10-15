/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        poj1068.cpp
*  Create Date: 2013-10-10 15:03:52
*  Descripton:  poj1069, simulate 
*/

#include <cstdio>
#include <cstring>

const int MAXN = 250;
bool l[MAXN];
int stk[MAXN], t, n, tt;

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(l, 0, sizeof(l));
		scanf("%d", &n);
		int cur = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tt);
			l[tt + i] = 1;
		}
		int c = 0, f = 1;
		for (int i = 1; i <= 2 * n; i++)
			if (l[i] == 0)
				stk[c++] = i;
			else {
				c--;
				int cnt = 0;
				for (int j = stk[c]; j <= i; j++)
					if (l[j]) cnt++;
				if (f) {
					printf("%d", cnt);
					f = 0;
				} else printf(" %d", cnt);
			}
		printf("\n");
	}
	return 0;
}

