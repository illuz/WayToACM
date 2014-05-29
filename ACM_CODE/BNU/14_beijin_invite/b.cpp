/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        b.cpp
*  Create Date: 2014-05-29 14:43:59
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

const int N = 44;
const double EPS = 1e-8;

ll t, n, x[N], mmin;
set<int> s;

void deal(int lhs, int rhs) {
	int cnt;
	ll dis = x[rhs] - x[lhs];
	// 如果在同一点就作为间距为0的情况处理
	if (dis == 0) {
		mmin = min(mmin, n - (rhs - lhs + 1));
		return;
	}
	// 枚举lhs和rhs中有k个间距，也可以枚举树
	for (int k = 2; k < n; k++) {
		cnt = 2;
		// 在中间的树中找要不用移动的树
		for (int i = lhs + 1; i < rhs; i++) {
			if (x[i] != x[i - 1] && x[i] > x[lhs] && x[i] < x[rhs] && (x[i] - x[lhs]) * k % dis == 0)
				cnt++;
		}
		mmin = min(mmin, n - cnt);
	}
}

int main()
{
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		cin >> n;
		s.clear();
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		if (n <= 2) {
			printf("Case #%d: 0\n", cas);
			continue;
		}
		mmin = N;
		sort (x, x + n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				deal(i, j); 
			}
		}
		printf("Case #%d: ", cas);
		cout << mmin << endl;
	}
	return 0;
}
