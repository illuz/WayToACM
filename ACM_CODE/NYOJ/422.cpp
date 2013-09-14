 /*
 *   Author:        illuz <iilluzen@gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          422.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-08-29 19:01:05
 *   Descripton:    nyoj422.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define repf(i, a, b) for (int i = (a); i <= (b); i++)

/****** TEMPLATE ENDS ******/

const int MAXN = 1000100;
int t, m, a, s[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &m);
		s[0] = 0;
		int Min = 110;
		repf(i, 1, m) {
			scanf("%d", &a);
			s[i] = s[i - 1] + a;
			Min = min(abs(s[i]), Min);
		}
		sort(s + 1, s + m + 1);
		int Max = max(max(abs(s[1]), s[m]), abs(s[m] - s[1]));
		for (int i = 2; i <= m && Min; i++)
			Min = min(s[i] - s[i - 1], Min);
		printf("%d\n", Max - Min);
	}
	return 0;
}

