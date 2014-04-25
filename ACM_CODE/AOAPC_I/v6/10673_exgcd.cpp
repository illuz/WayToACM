/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        10673_exgcd.cpp
*  Create Date: 2014-04-22 15:41:29
*  Descripton:  ex_gcd 
*/

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

int t, n, k;

void ex_gcd(ll a, ll b, ll& d, ll& x, ll&y)
{
	if (!b) {
		d = a;
		x = 1;
		y = 0;
	}
	else {
		ex_gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		cin >> n >> k;
		ll f = floor(n * 1. / k);
		ll c = ceil(n * 1. / k);
		ll d, x, y;
		ex_gcd(f, c, d, x, y);
		x *= n / d;
		y *= n / d;
		cout << x << ' ' << y << endl;
	}
	return 0;
}

