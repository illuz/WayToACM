/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1346.cpp
*  Create Date: 2014-02-23 15:16:10
*  Descripton:   
*/

#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 1<<16+1;

pair<double, int> s[N];

int n, q;
double l, f;

int main() {
	while (~scanf("%d", &n)) {
		rep(i, n) {
			scanf("%d%lf%lf", &s[i].second, &l, &f);
			s[i].first = l / f;
		}
		sort(s, s + n);
		scanf("%d", &q);
		printf("%d\n", s[q - 1].second);
	}
	return 0;
}

