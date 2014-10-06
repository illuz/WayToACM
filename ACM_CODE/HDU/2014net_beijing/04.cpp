/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        04.cpp
*  Create Date: 2014-10-06 10:18:29
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

int t, n, c;
double k, sum;

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d", &n);
		sum = 0.0;
		repf (i, 1, n) {
			scanf("%lf", &k);
			sum += k;
		}
		repf (i, 1, n)
			scanf("%d", &c);
		printf("Case #%d: %.6f\n", cas, (n + 1.0) / sum);
	}
	return 0;
}

