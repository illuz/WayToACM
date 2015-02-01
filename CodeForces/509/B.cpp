/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2015-01-31 20:31:50
*  Descripton:  Construction
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 101;

int n, k;

int main() {
	while (cin >> n >> k) {
		vector<vector<int> > piles(n);
		vector<int> a(n);
		int mmax = 0, mmin = N;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			mmax = max(mmax, a[i]);
			mmin = min(mmin, a[i]);
		}

		if (mmax - mmin > k) {
			puts("NO");
			continue;
		}

		puts("YES");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < mmin; ++j)
				piles[i].push_back(1);
			for (int j = mmin; j < a[i]; ++j)
				piles[i].push_back(j - mmin + 1);
		}

		for (auto &i : piles) {
			for (auto &j : i)
				cout << j << ' ';
			cout << endl;
		}
	}
	return 0;
}

