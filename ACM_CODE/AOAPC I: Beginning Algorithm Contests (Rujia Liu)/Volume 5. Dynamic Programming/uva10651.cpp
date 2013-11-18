/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10651.cpp
*  Create Date: 2013-11-07 20:32:06
*  Descripton:  dp, bit 
*/

#include <cstdio>
#include <cstring>

#define min(a, b) (a) < (b) ? (a) : (b)

const int MAXN = 4100;

int vis[MAXN], Min;
char ch[13];

bool check(int x, int i) {
	if ((x & (1 << (i - 1))) && (x & (1 << i)) && !(x & (1 << (i + 1))))
		return true;
	if (!(x & (1 << (i - 1))) && (x & (1 << i)) && (x & (1 << (i + 1))))
		return true;
	return false;
}

void dp(int x) {
	if (vis[x]) return;
	for (int i = 1; i <= 10; i++)
		if (check(x, i)) {
			int t = x;
			t ^= 1 << (i - 1);
			t ^= 1 << i;
			t ^= 1 << (i + 1);
			dp(t);
		}
	int cnt = 0;
	for (int i = 0; i < 12; i++)
		if (x & (1 << i))
			cnt++;
	Min = min(Min, cnt);
	vis[x] = cnt;
}

int main() {
	int n;
	scanf("%d\n", &n);
	while (n--) {
		memset(vis, 0, sizeof(vis));
		gets(ch);
		int a = 0;
		for (int i = 0; i < 12; i++)
			if (ch[i] == 'o')
				a |= (1 << i);
		Min = 13;
		dp(a);
		printf("%d\n", Min);
	}
	return 0;
}

