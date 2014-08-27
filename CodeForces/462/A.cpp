/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        A.cpp
*  Create Date: 2014-08-26 22:35:32
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 110;

char mp[N][N];
int t;

int main() {
	scanf("%d", &t);
	repf (i, 1, t) {
		scanf("%s", mp[i] + 1);
	}
	repf (i, 1, t)
		repf (j, 1, t) {
			int cnt = 0;
			if (mp[i + 1][j] == 'o') cnt++;
			if (mp[i][j + 1] == 'o') cnt++;
			if (mp[i - 1][j] == 'o') cnt++;
			if (mp[i][j - 1] == 'o') cnt++;
			if (cnt&1) {
				puts("NO");
				return 0;
			}
		}
	puts("YES");
	return 0;
}

