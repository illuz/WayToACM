/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-08-01 23:37:21
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 1e5+10;
int n, a[N];

void read() {
	scanf("%d", &n);
	rep (i, n)
		scanf("%d", &a[i]);
}

int solve() {
	if (a[0] < a[n-1]) {
		// must no decreace
		rep (i, n - 1) {
			if (a[i] > a[i + 1]) {
				return -1;
			}
		}
		return 0;
	}

	// find first
	int i = 0;
	while (i < n - 1) {
		if (a[i] > a[i+1]) {
			break;
		}
		i++;
	}
	int p = ++i;	// record

	// find second
	while (i < n - 1) {
		if (a[i] > a[i+1]) {
			break;
		}
		i++;
	}

	if (i >= n - 1) {
		return n - p;
	} else {
		return -1;
	}
}

int main() {
	read();
	printf("%d\n", solve());
	return 0;
}

