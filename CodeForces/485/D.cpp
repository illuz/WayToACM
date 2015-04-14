/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-11-07 12:28:52
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 2e6 + 10;

int ck[N], a[N], t, mmax;
int n, ans;

int main() {
	scanf("%d", &n);
	repf (i, 0, n - 1) {
		scanf("%d", &t);
		a[t] = 1;
		mmax = max(mmax, t);
	}
	repf (i, 1, mmax * 2) {
		if (a[i - 1]) ck[i] = i - 1;
		else ck[i] = ck[i - 1];
	}
	repf (j, 2, mmax)
		if (a[j]) {
			for (int i = j; i <= mmax * 2; i += j)
				if (ck[i] >= j)
					ans = max(ans, ck[i] % j);
		}
	cout << ans << endl;
	return 0;
}

