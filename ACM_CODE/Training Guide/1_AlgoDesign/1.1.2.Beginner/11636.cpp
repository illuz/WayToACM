/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        uva11636.cpp
*  Create Date: 2014-02-16 18:57:28
*  Descripton:   
*/

#include <cstdio>
#include <cmath>

int n, cas;

int main() {
	while (scanf("%d", &n) && n >= 0)
		printf("Case %d: %.0f\n", ++cas, ceil(log2(n)));
	return 0;
}

