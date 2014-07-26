/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-07-07 15:13:55
*  Descripton:  
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int t, a, b;
ll n, s1, v1, s2, v2;

int main() {
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		cin >> n >> s1 >> v1 >> s2 >> v2;
		ll mmax = 0;
		if (s1 > 10000 || s2 > 10000) {
			if (s1 < s2) {
				swap(s1, s2);
				swap(v1, v2);
			}
			int sz = n / s1;
			for (a = 0; a <= sz; a++) {
				b = (n - a * s1) / s2;
				mmax = max(mmax, a * v1 + b * v2);
			}
		} else {
			if (v1*s2 < v2*s1) {
				swap(s1, s2);
				swap(v1, v2);
			}
			a = n / s1;
			int r = n - a * s1;
			for (int i = 0; i <= s2; i++) {
				b = r / s2;
				mmax = max(mmax, a * v1 + b * v2);
				a--;
				r += s1;
			}
		}
		printf("Case #%d: ", cas);
		cout << mmax << endl;
	}
	return 0;
}

