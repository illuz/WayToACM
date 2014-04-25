/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        10717.cpp
*  Create Date: 2014-04-22 16:47:10
*  Descripton:  lcm 
*/

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 55;
const int INF = 0x7fffffff;

int n, t;
ll num[N], h, mmin, dis, tmp, dtmp;
bool flag;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	while (~scanf("%d%d", &n, &t) && (n || t)) {
		for (int i = 0; i < n; i++)
			cin >> num[i];
		while (t--) {
			cin >> h;
			dis = mmin = INF;
			flag = true;
			for (int i = 0; i < n && flag; i++)
				for (int j = i + 1; j < n && flag; j++)
					for (int k = j + 1; k < n && flag; k++)
						for (int l = k + 1; l < n && flag; l++) {
							ll mid = lcm(num[i], lcm(num[j], lcm(num[k], num[l])));
							tmp = h % mid;
							dtmp = mid - tmp;
							if (tmp == 0) {
								dis = 0;
								mmin = 0;
								flag = false;
							} else {
								if (tmp < mmin)
									mmin = tmp;
								if (dtmp < dis)
									dis = dtmp;
							}
						}
			cout << h - mmin << ' ' << h + dis << endl;
		}
	}
	return 0;
}

