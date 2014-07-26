/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1001.cpp
*  Create Date: 2014-07-22 13:22:17
*  Descripton:   
*/

#include <cstdio>
#include <cstring>

int k, p;

int main() {
	while (~scanf("%d%d", &k, &p)) {
		if ((k / (p - 1)) % 2) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}

