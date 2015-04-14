/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-11-06 19:19:47
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int INF = 1e9+10;

int maxx, minx, maxy, miny;
int n, x, y;

int main() {
	cin >> n;
	maxx = maxy = -INF;
	minx = miny = INF;
	while (n--) {
		cin >> x >> y;
		maxx = max(x, maxx);
		minx = min(x, minx);
		maxy = max(y, maxy);
		miny = min(y, miny);
	}
	ll ans = max(maxx - minx, maxy - miny);

	cout << ans * ans << endl;
	return 0;
}

