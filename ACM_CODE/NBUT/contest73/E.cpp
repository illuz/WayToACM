/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        E.cpp
*  Create Date: 2014-07-09 16:49:20
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

char P[N];
int f[N];

void getVal(int l) {
	int i = 0, j = -1;
	f[0] = -1;
	while (i < l) {
		if (j == -1 || P[i] == P[j]) {
			i++; j++;
			f[i] = j;
		} else j = f[j];
	}
}


int main() {
	while (~scanf("%s", P)) {
		int len = strlen(P);
		getVal(len);
		bool ok = true;
		if (f[len] > 0 && len % (len - f[len]) == 0) {
			puts("Win");
		} else {
			puts("Lost");
		}
	}
	return 0;
}

