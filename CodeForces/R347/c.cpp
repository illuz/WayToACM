/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        c.cpp
*  Create Date: 2013-09-21 00:41:09
*  Descripton:  gcd 
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repu(i, a, b) for (int i = (a); i < (b); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;

/****** TEMPLATE ENDS ******/

const int MAXN = 101;
LL g, t;

LL gcd(LL a, LL b) {
	if(b == 0)
		return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	LL Max = 0;
	cin >> n;
	rep(i, n) {
		cin >> t;
		if (i)
			g = gcd(g, t);
		else
			g = t;
		Max = max(Max, t);
	}
	LL cnt = Max / g - n;
	if (cnt % 2 == 0) printf("Bob\n");
	else printf("Alice\n");
	return 0;
}


