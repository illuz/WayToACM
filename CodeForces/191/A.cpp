/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1.cpp
*  Create Date: 2014-08-08 15:06:48
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 26;

int n;
int d[N][N];
char s[11];

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		int len = strlen(s);
		int fi = s[0] - 'a', la = s[len-1] - 'a';
		repf (i, 0, N - 1) {
			if (d[i][fi] != 0) {
				d[i][la] = max(d[i][la], d[i][fi] + len);
			}
		}
		d[fi][la] = max(d[fi][la], len);
	}
	int ans = 0;
	repf (i, 0, N - 1)
		ans = max(d[i][i], ans);
	printf("%d\n", ans);
	return 0;
}

