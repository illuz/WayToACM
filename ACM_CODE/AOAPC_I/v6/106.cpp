/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        106.cpp
*  Create Date: 2014-04-22 14:56:00
*  Descripton:   
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1000100;

bool used[N];

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	ll n, a, b, c;
	ll cnt1, cnt2;
	while (cin >> n) {
		cnt1 = cnt2 = 0;
		memset(used, 0, sizeof(used));
		ll m = sqrt(n + 0.5);
		for (ll x = 1; x <= m; x++)
			for (ll y = x + 1; y <= m; y += 2) {
				if (gcd(x, y) != 1)
					continue;
				// calculate the a, b, c
				a = y * y - x * x;
				b = 2 * x * y;
				c = y * y + x * x;
				if (c > n)
					break;
				cnt1++;
				ll ta = a, tb = b, tc = c;
				while (tc <= n) {
					used[ta] = used[tb] = used[tc] = 1;
					ta += a;
					tb += b;
					tc += c;
				}
			}
		for (int i = 1; i <= n; i++)
			if (!used[i])
				cnt2++;

		cout << cnt1 << ' ' << cnt2 << endl;
	}
	return 0;
}

