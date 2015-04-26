/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-11-08 19:05:08
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
int t, n, k;

int f2(int n, int k) {
	if (n < k) return n * n;
	else return f2(n - k, k);
}

int f(int n, int k) {
	if (n < k) return n * n;
	if (n % k) {
		int a = n / k, b = n % k;
		return min(f(k * a - b, k), f2(k * a - b, k));
	} else
		return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		if (n < k)
			puts("0");
		else
			printf("%d\n", n * n - min(f(n, k), f2(n, k)));
	}
	return 0;
}

