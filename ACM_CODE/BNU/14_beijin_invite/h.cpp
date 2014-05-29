/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        h.cpp
*  Create Date: 2014-05-29 13:34:00
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10;
const int K = 60;
char str[K];
int t, n, k;
ll mmax, mmin;
struct S {
	ll val;
	int pos;
} v[N], vv[N];

bool cmp1(const S a, const S b) {
	return a.val > b.val;
}

bool cmp2(const S a, const S b) {
	return a.val < b.val;
}

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			ll t1 = 0, t2 = 0;
			for (int j = 0; j < k; j++) {
				if (str[j] == '0') {
					t1 += ((ll)1<<(k - j - 1));
				} else {
					t2 += ((ll)1<<(k - j - 1));
				}
			}
			if (t1 < t2)
				swap(t1, t2);
			v[i].val = t1;
			vv[i].val = t2;
			vv[i].pos = v[i].pos = i;
		}
		printf("Case #%d: ", cas);
		if (n == 1) {
			puts("0");
			continue;
		}
		sort (v, v + n, cmp1);
		sort (vv, vv + n, cmp2);
		if (v[0].pos != vv[0].pos) {
			mmax = v[0].val;
			mmin = vv[0].val;
		} else if (v[0].val - v[1].val > vv[1].val - vv[0].val) {
			mmax = v[0].val;
			mmin = vv[1].val;
		} else {
			mmax = v[1].val;
			mmin = vv[0].val;
		}
		cout << mmax - mmin << endl;
	}
	return 0;
}

