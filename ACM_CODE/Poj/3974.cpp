/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3068.cpp
*  Create Date: 2014-02-06 13:06:32
*  Descripton:   
*/

#include <cstdio>
#include <cstring>

int min(int a, int b) { return a > b ? b : a; }

const int N = 1000010;
char s[N], t[2*N];
int p[2*N];

int main() {
	int cas = 0;
	while (scanf("%s", s) == 1) {
		if (s[0] == 'E') break;
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

		printf("Case %d: %d\n", ++cas, mmax - 1);

	}
	return 0;
}
