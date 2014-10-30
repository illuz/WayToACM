/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        I.cpp
*  Create Date: 2014-10-12 10:32:24
*  Descripton:   
*/

// #define HDU
// don't forget to change lld to I64d

#ifdef HDU
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <utility>
#include <cctype>
typedef __int64 ll;
#else	// c++11
#include <bits/stdc++.h>
typedef long long ll;
#endif

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 110;

double res, x;
int t, n;
char uni[5];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &n, uni);
		res = 0;
		if (uni[0] == 'b') {
			repf (i, 1, n) {
				scanf("%lf", &x);
				x /= 100;
				if (x == 0) continue;
				res += (1.0 * x * log10(x) / log10(2));
			}
		} else if (uni[0] == 'n') {
			repf (i, 1, n) {
				scanf("%lf", &x);
				x /= 100;
				if (x == 0) continue;
				res += (1.0 * x * log(x));
			}
		} else {
			repf (i, 1, n) {
				scanf("%lf", &x);
				x /= 100;
				if (x == 0) continue;
				res += (1.0 * x * log10(x) / log10(10));
			}
		}
		printf("%.8f\n", -res);
	}
	return 0;
}

