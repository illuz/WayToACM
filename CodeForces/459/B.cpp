/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-08-15 23:51:15
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 2e5 + 10;

ll t, mmax, mmin;
ll a[N];

int main() {
	while (cin >> t) {
		repf (i, 0, t - 1) {
			cin >> a[i];
		}
		sort (a, a + t);
		if (a[0] == a[t - 1]) {
			cout << 0 << ' ' << t * (t - 1) / 2 << endl;
			continue;
		}

		mmax = 0;
		mmin = 0;
		int i = 0;
		while (i < t && a[i] == a[0])
			mmin++, i++;

		i = t - 1;
		while (i >= 0 && a[i] == a[t - 1])
			mmax++, i--;

		cout << a[t - 1] - a[0] << ' ' << mmin * mmax << endl;
	}
	return 0;
}

