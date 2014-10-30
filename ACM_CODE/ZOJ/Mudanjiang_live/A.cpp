/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-10-12 10:15:01
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

const int N = 0;

int n, m, t, x;
double a, b;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		a = b = 0;
		repf (i, 1, n - 1) {
			scanf("%d", &x);
			a += x;
		}
		a = a / (n - 1) - 0.000001;
		repf (i, 0, m - 1) {
			scanf("%d", &x);
			b += x;
		}
		b = b / m + 0.000001;
		printf("%d %d\n", (int)ceil(b), (int)floor(a));
	}

	return 0;
}

