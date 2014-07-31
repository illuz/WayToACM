/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1011.cpp
*  Create Date: 2014-07-24 12:33:06
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;

struct Problem {
	int e;
	int k;
	double r;
} p[N];

bool cmp(Problem a, Problem b) {
	return a.r > b.r;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i].e);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i].k);
		p[i].r = (double) p[i].k / p[i].e;
	}
	sort(p, p + n, cmp);
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i].e;
		ans += sum * p[i].k;
	}
	cout << ans << endl;
	return 0;
}

