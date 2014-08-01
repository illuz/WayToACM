/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-08-01 23:31:42
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d",&x)
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
	int n;
	RI(n);

	int t = n / 2;
	rep (i, n) {
		rep (j, n) {
			int a = abs(i - t), b = abs(j - t);
			if (a + b <= t) {
				cout << 'D';
			} else {
				cout << '*';
			}
		}
			cout << endl;
	}
	return 0;
}

