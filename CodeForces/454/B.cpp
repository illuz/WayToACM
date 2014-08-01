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
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define RI(x) scanf("%d",&x)
#define PIN(x) printf("%d\n",x)
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 1e5+10;
int n, a[N];

int main() {
	RI(n);
	rep (i, n) RI(a[i]);
	if (a[0] < a[n-1]) {
		bool f = 1;
		rep (i, n - 1) {
			if (a[i] > a[i + 1]) {
				f = 0;
				break;
			}
		}
		if (f) PIN(0);
		else PIN(-1);
		return 0;
	}
	int i = 0;
	while (i < n - 1) {
		if (a[i] > a[i+1]) {
			break;
		}
		i++;
	}
	int p = ++i;

	while (i < n - 1) {
		if (a[i] > a[i+1]) {
			break;
		}
		i++;
	}
	if (i >= n - 1) {
		PIN(n - p);
	} else {
		PIN(-1);
	}

	return 0;
}

