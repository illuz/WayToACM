/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3068.cpp
*  Create Date: 2014-02-06 11:51:50
*  Descripton:   
*/

#include <cstdio>
#include <cstring>

int min(int a, int b) { return a > b ? b : a; }

const int N = 110010;
char s[N], t[2*N];
int p[2*N];

int main() {
	while (scanf("%s", s) == 1) {
		// deal
		t[0] = '$';
		int len = strlen(s), j = 1;
		for (int i = 0; i < len; i++) {
			t[j++] = '#';
			t[j++] = s[i];
		}
		t[j++] = '#';

		memset(p, 0, sizeof(p));
		int mx = 0, id = 0, mmax = 0;
		for (int i = 1; i < j; i++) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (t[i + p[i]] == t[i - p[i]])
			   	p[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
			if (mmax < p[i]) 
				mmax = p[i];
		}

		printf("%d\n", mmax - 1);

	}
	return 0;
}
