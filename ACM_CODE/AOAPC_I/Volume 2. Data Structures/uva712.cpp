/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva712.cpp
*  Create Date: 2013-12-05 18:41:59
*  Descripton:  simulate 
*/

#include <cstdio>

const int MAXN = 1 << 7 + 2;
char ch[MAXN], op[MAXN];

int main() {
	int n, t, cas = 1;
	while (scanf("%d\n", &n) && n) {
		gets(ch);
		gets(ch);
		scanf("%d\n", &t);
		printf("S-Tree #%d:\n", cas++);
		for (int i = 0; i < t; i++) {
			gets(op);
			int pos = 1;
			for (int j = 0; j < n; j++)
				if (op[j] == '0')
					pos = pos << 1;
				else
					pos = (pos << 1) + 1;
			printf("%c", ch[pos - (1 << n)]);
		}
		puts("\n");
	}
	return 0;
}

