/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-11-08 20:24:45
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

const int N = 0;

int t, n, k;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		if (n < k)
			puts("0");
		else {
			int m = n % k;
			if (m > k / 2)
				m = k - m;
			printf("%d\n", n * n - m * m);
		}
	}
	return 0;
}

