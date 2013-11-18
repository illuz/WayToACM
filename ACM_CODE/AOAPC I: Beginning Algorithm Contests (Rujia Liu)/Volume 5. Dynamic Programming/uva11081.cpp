/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva11081.cpp
*  Create Date: 2013-11-17 18:48:52
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>

const int MAXN = 70;
int la, lb, lc;
int f1[MAXN][MAXN][MAXN], f2[MAXN][MAXN][MAXN], f[MAXN][MAXN][MAXN];
char a[MAXN], b[MAXN], c[MAXN];

int main() {
	int i, j, k, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s%s", a + 1, b + 1, c + 1);
		la = strlen(a + 1);
		lb = strlen(b + 1);
		lc = strlen(c + 1); memset(f1, 0, sizeof(f1));
		memset(f2, 0, sizeof(f2));
		memset(f, 0, sizeof(f));
		for (int i = 0; i <= la; i++)
			for (int j = 0; j <= lb; j++)
				f[i][j][0] = f1[i][j][0] = f2[i][j][0] = 1;

		for (int k = 1; k <= lc; k++) 
			for (int i = 0; i <= la; i++)
				for (int j = 0; j <= lb; j++) {
					if (i) {
						f1[i][j][k] = f1[i - 1][j][k];
						if (a[i] == c[k])
							f1[i][j][k] += f[i - 1][j][k - 1];
						f1[i][j][k] %= 10007;
					}
					if (j) {
						f2[i][j][k] = f2[i][j - 1][k];
						if (b[j] == c[k])
							f2[i][j][k] += f[i][j - 1][k - 1];
						f2[i][j][k] %= 10007;
					}
					f[i][j][k] = (f1[i][j][k] + f2[i][j][k]) % 10007;
				}
		printf("%d\n", f[la][lb][lc]);
	}
	return 0;
}

