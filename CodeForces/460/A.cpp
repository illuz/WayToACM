/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-08-20 23:32:18
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)

int main() {
	int n, m;
	int days = 0;
	scanf("%d%d", &n, &m);
	repf (i, 0, 1000) {
		if ((i - 1) / m + n >= i) {
			days = i;
		} else break;
	}
	printf("%d\n", days);
	return 0;
}

