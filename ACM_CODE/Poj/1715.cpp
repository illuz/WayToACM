/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1715.cpp
*  Create Date: 2014-05-27 09:11:41
*  Descripton:   
*/

#include <cstdio>

char ch[20], res[10];
int n;

int P(int tot, int get) {
	int ret = 1;
	while (get--) {
		ret *= tot;
		tot--;
	}
	return ret;
}

void init() {
	for (int i = 0; i < 10; i++)
		ch[i] = '0' + i;
	for (int i = 0; i < 6; i++)
		ch[i + 10] = 'A' + i;

}

void solve(int n) {
	bool vis[16] = {0}, head = false;
	int used = 0, tmp;
	for (int i = 8; i > 0; i--) {
		int j;
		for (j = 15; j > 0; j--) {
			if (!vis[j]) {
				tmp = P(16 - used - 1, i - 1);
				if (tmp < n) {
					n -= tmp;
				} else {
					vis[j] = true;
					break;
				}
			}
		}
		res[i] = ch[j];
		if (head || j != 0)
			used++;
		if (j != 0)
			head = true;
	}
}


int main()
{
	init();

	scanf("%d", &n);

	solve(n);
	bool head = false;
	for (int i = 8; i > 0; i--)
		if (head || res[i] != '0') {
			printf("%c", res[i]);
			head = true;
		}
	puts("");

	return 0;
}

