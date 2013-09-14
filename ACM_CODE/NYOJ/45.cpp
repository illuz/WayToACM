 /*
 *   Author:        illuz <iilluzen[at]gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          45.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-08-31 19:39:38
 *   Descripton:    nyoj 45, cheesboard coverage, wan jin zhi 
 */
#include <cstdio>

const int MAXN = 100;
int a[MAXN];			// 万进制，每位存4进制

int main() {
	int n, m, c;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		if (m == 1) {
			printf("1\n");
			continue;
		}
		a[0] = 1;
		int t = 0;			// 已经用到第几位
		for (int i = 1; i < m; i++) {
			c = 0;		// c为进位数
			for (int j = 0; j <= t; j++) {
				a[j] = a[j] * 4 + c;
				c = a[j] / 10000;
				a[j] %= 10000;
			}
			if (c != 0) {
				t++;
				a[t] = c;
			}
			a[0]++;
		}
		// 处理最后的进位，其实就是99999999这种情况，这里可以不用
//		for (int j = 0; j <= t; j++) {
//			c = a[j] / 10000;
//			a[j] %= 10000;
//		}
//		if (c != 0) {
//			t++;
//			a[t] = c;
//		}
		printf("%d", a[t]);
		for (int i = t - 1; i >= 0; i--)
			printf("%04d", a[i]);
		printf("\n");
	}
	return 0;
}

