/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        07.cpp
*  Create Date: 2014-09-21 12:13:47
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef __int64 ll;

const int N = 1e6 + 10;

ll n, a[N], t;
map<ll, int> mp;

int main() {
	int T;
	ios_base::sync_with_stdio(0);
	scanf("%d", &T);
	repf (cas, 1, T) {
		scanf("%I64d", &n);
		mp.clear();
		repf (i, 0, n - 1) {
			scanf("%I64d", &t);
			mp[10000 - (100 - t) * (100 - t)]++;
		}
		// check
		bool ok = false;
		int app = mp[10000 - (100 - t) * (100 - t)];
		int mmax = 0;
		for (map<ll, int>::iterator i = mp.begin(); i != mp.end(); i++) {
			if ((*i).second != app)
				ok = true;
			mmax = max((*i).second, mmax);
		}
		printf("Case #%d:\n", cas);
		// printf("%d\n", mp.size());
		if (mp.size() == 1) {
			printf("%I64d\n", 10000 - (100 - t) * (100 - t));
			continue;
		}
		if (ok == false) {
			puts("Bad Mushroom");
			continue;
		}
		bool first = 1;
		for (map<ll, int>::iterator i = mp.begin(); i != mp.end(); i++) {
			if ((*i).second == mmax) {
				if (first)
					printf("%I64d", (*i).first), first = 0;
				else
					printf(" %I64d", (*i).first);
			}
		}
		puts("");
	}
	return 0;
}

