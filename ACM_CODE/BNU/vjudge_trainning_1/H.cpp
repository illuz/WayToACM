/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        H.cpp
*  Create Date: 2014-10-11 11:53:18
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

int n, ans, a;

int main() {
	// ios_base::sync_with_stdio(0);
	while (~scanf("%d", &n)) {
		ans = 0;
		repf (i, 1, n + 1) {
			scanf("%d", &a);
			ans ^= a;
			ans ^= i;
		}
		printf("%d\n", ans^(n + 1));
	}

	return 0;
}

