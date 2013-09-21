/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        c.cpp
*  Create Date: 2013-09-21 00:41:09
*  Descripton:  gcd 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long LL;

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


