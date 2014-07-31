/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-06-19 23:49:53
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 320;
char P[MAXN];

bool equal(char a, char b) {
	if (a == 0 || b == 0)
		return true;
	return a == b;
}

bool check(int beg, int len) {
	for (int i = 0; i < len / 2; i++) {
		if (!equal(P[beg + i], P[beg + len/2 + i]))
			return false;
	}
	return true;
}

int main() {
	int cas = 1, len, k;
	memset(P, 0, sizeof(P));
	scanf("%s%d", P, &k);
	len = strlen(P);

	if (len <= k) {
		if ((len + k) % 2)
			printf("%d\n", len + k - 1);
		else
			printf("%d\n", len + k);
		return 0;
	}

	for (int i = (len + k); i > 0; i--)
		if (i % 2 == 0){
			for (int j = 0; j + i <= len + k; j++) {
				if (check(j, i)) {
					printf("%d\n", i);
					return 0;
				}
			}
		}
	return 0;
}

