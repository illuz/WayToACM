/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-07-09 14:55:54
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

const int N = 1e4 + 10;
int t, n;
double price[N];

int main() {
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &price[i]);
		}
		sort(price, price + n);
		double res = 0;
		int mid = (n - 1) / 2;
		for (int i = 0; i < n; i++) {
			res += fabs(price[i] - price[mid]);
		}
		printf("Case %d:%.6f %.6f\n", cas, price[mid], res);
		if (cas != t) {
			puts("");
		}
	}
	return 0;
}

