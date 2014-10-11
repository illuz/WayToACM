/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-10-11 09:13:31
*  Descripton:   
*/

#define HDU
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

const int N = 210;

int n, m, a, sum;

int main() {
	while (~scanf("%d", &n)) {
		sum = 0;
		repf (i, 1, n) {
			scanf("%d", &a);
			sum += a;
		}
		scanf("%d", &m);
		repf (i, 1, m)
			scanf("%d", &a);
		if (sum == 0)
			puts("0.00");
		else if (n == m)
			puts("inf");
		else
			printf("%.2f\n", 1.0 * sum / (n - m));
	}
	return 0;
}

