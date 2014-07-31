/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1.cpp
*  Create Date: 2014-07-27 15:01:54
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6;
int n, a[N];

int main() {
	scanf("%d", &n);
	rep(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 0;
	rep (i, n - 1) {
		ans = max(ans, a[i]&a[i+1]);
	}
	PIN(ans);
	return 0;
}

