/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1150.cpp
*  Create Date: 2014-05-26 22:28:45
*  Descripton:  
*/

#include <cstdio>
#include <cstring>

const int N = 2e5;

int cnt3, cnt7, cnt9, cnt2;
int n, m;
int rec[10][N];

// 计算n!中消除2,5后末位为x的数量
int f(int n, int k) {
	if (n < 1)
		return 0;
	if (n < N && rec[k][n] != -1)
		return rec[k][n];
	int ret = n / 10 + (n % 10 >= k) + f(n / 2, k) + f(n / 5, k) - f(n / 10, k);
	if (n < N)
		rec[k][n] = ret;
	return ret;
}

// 多出来的2的个数
int more(int n) {
	int num2 = 0, num5 = 0;
	int t = n;
	while (t != 0) {
		num2 += t / 2;
		t /= 2;
	}
	while (n != 0) {
		num5 += n / 5;
		n /= 5;
	}
	return num2 - num5;
}

int main()
{
	memset(rec, -1, sizeof(rec));
	while (~scanf("%d%d", &n, &m)) {
		if (m == 0) {
			puts("1");
			continue;
		}
		m = n - m;
		cnt2 = more(n) - more(m);
		cnt3 = f(n, 3) - f(m, 3);
		cnt7 = f(n, 7) - f(m, 7);
		cnt9 = f(n, 9) - f(m, 9);
		// printf("%d %d %d %d\n", cnt2, cnt3, cnt7, cnt9);

		// 2 4 8 6
		if (cnt2-- == 0)
			cnt2 = 1;
		else if (cnt2 % 4 == 0)
			cnt2 = 2;
		else if (cnt2 % 4 == 1)
			cnt2 = 4;
		else if (cnt2 % 4 == 2)
			cnt2 = 8;
		else
			cnt2 = 6;

		// 1 3 9 7
		if (cnt3 % 4 == 0)
			cnt3 = 1;
		else if (cnt3 % 4 == 1)
			cnt3 = 3;
		else if (cnt3 % 4 == 2) cnt3 = 9;
		else
			cnt3 = 7;

		// 1 7 9 3
		if (cnt7 % 4 == 0)
			cnt7 = 1;
		else if (cnt7 % 4 == 1)
			cnt7 = 7;
		else if (cnt7 % 4 == 2)
			cnt7 = 9;
		else
			cnt7 = 3;

		// 1 9
		if (cnt9 % 2 == 0)
			cnt9 = 1;
		else
			cnt9 = 9;

		printf("%d\n", cnt2 * cnt3 * cnt7 * cnt9 % 10);
	}
	return 0;
}

