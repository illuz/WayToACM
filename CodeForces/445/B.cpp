/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-07-06 21:39:06
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

const int N = 50;

int fa[N], sum[N];
int n, m, a, b;

int find(int x) {
	if (fa[x] != x) return fa[x] = find(fa[x]);
	else return x;
}

ll power(ll x, ll n) {
	ll ans = 1;
	while (n) {
		if (n&1)
			ans *= x;
		x = x * x;
		n /= 2;
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		fa[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		fa[find(a)] = find(b);
	}
	for (int i = 1; i <= n; i++) {
		sum[find(i)]++;
	}

	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		if (sum[i] > 1) {
			ans *= power(2, sum[i] - 1);
		}
	}
	cout << ans << endl;
	return 0;
}

