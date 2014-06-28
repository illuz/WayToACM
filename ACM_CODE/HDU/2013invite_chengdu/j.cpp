/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        j.cpp
*  Create Date: 2014-05-09 14:32:28
*  Descripton:   
*/

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
using namespace std;
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi firsst
#define sd second
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 0;
int n;
int a, b, c, d, p, m;

int num(int r, int beg, int p)
{
	if (r == 0 || beg > r || beg <= 0 || beg > p)
		return 0;
	return (r - beg) / p + 1;
}

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	scanf("%d", &n);
	for (int cas = 1; cas <= n; cas++) {
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &p, &m);
		int l = a + c, r = b + d, mmin = min(b - a + 1, d - c + 1);
		int vp = l % p;
		int pos = (m - vp) % p + 1;
		int cnt = num(mmin - 1, pos, p);
		int ans = (pos + pos + (cnt - 1) * p) * cnt / 2;

		int eqr = r - l + 1 - (mmin - 1) * 2;
		vp = (l + mmin - 1) % p;
		pos = (m - vp) % p + 1;
		cnt = num(eqr, pos, p);
		ans += cnt * mmin;
		
		vp = r % p;
		pos = (vp  - m) % p + 1;
		cnt = num(mmin - 1, pos, p);
		ans += (pos + pos + (cnt - 1) * p) * cnt / 2;
		ll nn = (ll)(b - a + 1) * (d - c + 1);
		if (ans) {
			ll g = gcd(ans, nn);
			ans /= g;
			nn /= g;
		} else {
			nn = 1;
		}
		printf("Case #%d: ", cas);
		cout << ans << '/' << nn << endl;
	}
	return 0;
}

