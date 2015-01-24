/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2015-01-24 00:13:21
*  Descripton:  greedy
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll r, x, y, xx, yy;

int main() {
	while (cin >> r >> x >> y >> xx >> yy) {
		ll dx = (xx - x) * (xx - x);
		ll dy = (yy - y) * (yy - y);
		cout << ceil(sqrt( (dx + dy) * 1.0 / (4 * r * r))) << endl;
	}
	return 0;
}

