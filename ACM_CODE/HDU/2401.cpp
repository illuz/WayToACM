/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2401.cpp
*  Create Date: 2014-09-12 16:21:12
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 0;

int n, w, d, res;

int main() {
	while (~scanf("%d%d%d%d", &n, &w, &d, &res)) {
		int sum = w * (n - 1) * n / 2 - res;
		if (sum)
			printf("%d\n",  sum / d);
		else
			printf("%d\n", n);
	}
	return 0;
}

