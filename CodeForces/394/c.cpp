/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        c.cpp
*  Create Date: 2014-02-21 00:49:53
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define PS(x) printf("%s", x)
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 1001;

int a, b, c;
int n, m;
int g[N][N];
string s;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, n) rep(j, m) {
		cin >> s;
		if (s == "00") a++;
		else if (s == "11") b++;
		else c++;
	}
	rep(i, n) rep(j, m) {
		if (b) g[i][j] = 1, b--;
		else if (c) g[i][g[i][0] ? j : m - j - 1] = (i & 1) + 2, c--;
		else break;
	}
	rep(i, n) { 
		rep(j, m)
			if (g[i][j] == 0) PS("00 ");
			else if (g[i][j] == 1) PS("11 ");
			else if (g[i][j] == 2) PS("01 ");
			else PS("10 ");
		puts("");
	}
	return 0;
}

