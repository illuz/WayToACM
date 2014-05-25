/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1496.cpp
*  Create Date: 2014-05-24 23:38:54
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 27;

int c[N][N], len, sum;
char str[11];

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			if (!j || i == j)
				c[i][j] = 1;
			else
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	c[0][0] = 0;
}

int main() {
	init();

	while (~scanf("%s", str)) {
		len = strlen(str);
		bool flag = true;
		for (int i = 1; i < len; i++)
			if (str[i - 1] >= str[i]) {
				puts("0");
				flag = false;
			}
		if (!flag)
			continue;

		sum = 1;
		for (int i = 1; i < len; i++) {
			sum += c[26][i];
		}

		for (int i = 0; i < len; i++) {
			char ch = (0 == i) ? 'a' : str[i - 1] + 1;
			while (ch <= str[i] - 1) {
				sum += c['z' - ch][len - i - 1];
				ch++;
			}
		}

		printf("%d\n", sum);
	}
	return 0;
}

